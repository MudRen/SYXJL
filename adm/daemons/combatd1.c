// combatd.c
// �Ǻǣ�����by Ronger 01/99

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;
object *player;
int userno;
void compare(object killer,object victim);
int potential_lv(int exp);

string *guard_msg = ({
        CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
        CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
        CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
        CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
        CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
             HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
        HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
        HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
        HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
        HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
        HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
        HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *winner_msg = ({
        CYN "\n$N������Ц������˵���������ˣ�\n\n" NOR,
        CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR,
        CYN "\n$Nʤ�����У����Ծ�����ߣ�̾�������ǰν��Ĺ���ãȻ��\n\n" NOR,
        CYN "\n$n������˼�����˵�����ⳡ�����������ˣ��»ؿ�����ô��ʰ�㣡\n\n" NOR,
        CYN "\n$n���һ�ݣ��޺޵�˵�������ӱ���ʮ�겻��\n\n" NOR,
        CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
        CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

void create()
{
        seteuid(getuid());
        set("name", "ս������");
        set("channel_id", "ս������(combat)");
             set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;

        if( damage == 0 ) return "���û������κ��˺���\n";

        switch( type ) {
        case "����":
        case "����":
                if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
                else if( damage < 20 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 40 ) return "������͡���һ������һ���˿ڣ�\n";
                else if( damage < 80 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
                else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
                else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
                else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
           else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
                else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
                else return "���ֻ����$nһ���Һ���$w�Ѵ�$p��$l�Դ���������Ѫ�������أ���\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
                else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                else if( damage < 120 ) return "������项��һ����$n����������\n";
                else if( damage < 160 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
                else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
                else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
                else if( damage < 40 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
                else if( damage < 80 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
                else if( damage < 120 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
                else if( damage < 160 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else if( damage < 240 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
                else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
        break;
        default:
                if( !type ) type = "�˺�";
                if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
                else if( damage < 20 ) str = "��������΢��";
                else if( damage < 30 ) str = "������һ��";
                else if( damage < 50 ) str = "������һ������";
                else if( damage < 80 ) str = "��������Ϊ���ص�";
                else if( damage < 120 ) str = "�������൱���ص�";
                else if( damage < 170 ) str = "������ʮ�����ص�";
                else if( damage < 230 ) str = "�����ɼ������ص�";
                else str =  "�����ɷǳ����µ�����";
                return str + type + "��\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
        if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
        if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
        if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
             if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
        if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
        if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
        return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
        if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
        if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
        if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}
varargs void report_status(object ob, int effective)
{
// �����ֳ�ת�� start
        player=users();
// �����ֳ�ת�� end
        if( effective )
        {
                message_vision( "( $N" + eff_status_msg(
                        (int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") )
                        + " )\n", ob);
// �����ֳ�ת�� start
                if ((string)environment(ob)->query("short") == "��̨")
                for (userno=0; userno<sizeof(player); userno++)
                        if (player[userno]->query_temp("view_leitai"))
                                tell_object(player[userno], "( " + ob->name() + eff_status_msg(
                                (int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") )
                                + " )\n");
// �����ֳ�ת�� end
        }
        else
        {
                message_vision( "( $N" + status_msg(
                        (int)ob->query("qi") * 100 / (int)ob->query("max_qi") )
                        + " )\n", ob);
// �����ֳ�ת�� start
        if ((string)environment(ob)->query("short") == "��̨")
                for (userno=0; userno<sizeof(player); userno++)
                        if (player[userno]->query_temp("view_leitai"))
                                tell_object(player[userno], "( " + ob->name() + status_msg(
                                (int)ob->query("qi") * 100 / (int)ob->query("max_qi") )
                                + " )\n");
// �����ֳ�ת�� end
        }
}
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
        int level, power;

        if( !living(ob) ) return 0;

        level = ob->query_skill(skill);

        switch(usage) {
                case SKILL_USAGE_ATTACK:
                        level += ob->query_temp("apply/attack");
                break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
                        if (ob->is_fighting())
                                level = level * (100 + ob->query_temp("fight/dodge")) / 100;
                break;
        }

        if( !level ) return (int)ob->query("combat_exp") / 100;

        // here need a modification later
        power = (level / 3 / 50)*level*level;

        if (usage == SKILL_USAGE_ATTACK)
                return (power + ob->query("combat_exp")/50) / 30 * (ob->query_str() + ob->query_temp("str"));
        else
                return (power + ob->query("combat_exp")/50) / 30 * (ob->query_dex() + ob->query_temp("str"));
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type, string action_p)
{
        mapping my, your, prepare, action;
        string limb, *limbs, result;
        string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
        mixed foo;
        int ap, dp, pp;
        int damage, damage_bonus, defense_factor;
//      int cost;
        int wounded = 0;
// �����ֳ�ת�� start
        player=users();
// �����ֳ�ת�� end
        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();

        // (0) Choose skills.
        //
        prepare = me->query_skill_prepare();
        if (!prepare) prepare = ([]);

        if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
        else if ( sizeof(prepare) == 0) attack_skill = "unarmed";
        else if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
        else if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];


        //
        // (1) Find out what action the offenser will take.
        //
        me->reset_action();

        action = me->query("actions");

        if( !mapp(action) ) {
                me->reset_action();
                action = me->query("action");
                if( !mapp(action) ) {
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"), me->query("actions", 1)));
                        return 0;
                }
        }

        if (stringp(action_p))
                result = "\n" + action_p + "\n";
        else {
                if (me->query_temp("action_flag") == 0)
                        result = "\n" + action["action"] + "��\n";
                else
                        result = "\n" + "������"+action["action"] + "!\n";
        }

        //
        // (2) Prepare AP, DP for checking if hit.
        //
        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];

        ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        if( ap < 1) ap = 1;
        if (userp(me) && intp(action["dodge"]))
                me->set_temp("fight/dodge", action["dodge"]);

        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( dp < 1 ) dp = 1;
        if( ap > 1000000|| dp > 1000000) {
                ap=ap/1000;
                dp=dp/1000;
                pp=-1;
        }

        if( victim->is_busy() ) dp /= 3;
        //
        // (3) Fight!
        //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
        //     AP and DP are greater than zero, so we always have chance to hit
        //     or be hit.
        //

        if( random(100) < dp*100/(ap+dp) ) {            // Does the victim dodge this hit?

                dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

                if( dp < ap && (!userp(victim) || !userp(me))
                &&      random(your["jing"]*100/your["max_jing"] + your["int"]) > 50 ) {
                        your["combat_exp"] += 1;
                        victim->improve_skill("dodge", 1);
      }

                // This is for NPC only. NPC have chance to get exp when fail to hit.
                if( (ap < dp) && !userp(me) ) {
                        if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
                        me->improve_skill(attack_skill, random(my["int"]));
                }
                damage = RESULT_DODGE;

        } else {

                //
                //      (4) Check if the victim can parry this attack.
                //

                if( victim->query_temp("weapon") ) {
                        pp =(pp==-1)? skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/1000:
                                skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
                        if( !weapon ) pp *= 2;
                } else {
                        if( weapon ) pp = 0;
                        else pp =(pp==-1)? skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/1000:
                                 skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
        }

                if( victim->is_busy() ) pp /= 3;
                if( pp < 1 ) pp = 1;

                if( random(100)< pp*100/(ap+pp) ) 
                {
                        parry_skill = victim->query_skill_mapped("parry");
                        if( !parry_skill ) parry_skill = "parry";
                        // change to SKILL_D(parry_skill) after added parry msg to those
                        // martial arts that can parry.
                        result += SKILL_D("parry")->query_parry_msg(weapon);

                        if( dp < ap && (!userp(victim) || !userp(me))
                        &&      random(your["jing"]*100/your["max_jing"] + your["int"]) > 50 ) {
                                your["combat_exp"] += 1;
                                victim->improve_skill("parry", 1);
                        }
                        damage = RESULT_PARRY;

                } else {

                     //
                        //      (5) We hit the victim and the victim failed to parry
                    //

                        damage = me->query_temp("apply/damage");
                        damage = (damage + random(damage)) / 2;
                        if( action["damage"] )
                                damage += action["damage"] * damage / 100;

                        damage_bonus = me->query_str();

                        // Let force skill take effect.
                        if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
                                if( force_skill = me->query_skill_mapped("force") ) {
                                        foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
                                        if( stringp(foo) ) result += foo;
                                        else if( intp(foo) ) damage_bonus += foo;
                                }
                        }

                        if( action["force"] )
                                damage_bonus += action["force"] * damage_bonus / 100;

                        if( martial_skill = me->query_skill_mapped(attack_skill) ) {
                                foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        // Let weapon or monster have their special damage.
                        if( weapon ) {
                                foo = weapon->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        } else {
                                foo = me->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        if( damage_bonus > 0 )
                                damage += (damage_bonus + random(damage_bonus))/2;
                        if( damage < 0 ) damage = 0;

                        // Let combat exp take effect
                        defense_factor = your["combat_exp"];
                        while( random(defense_factor) > my["combat_exp"] ) {
                                                        damage -= damage / 3;
                                defense_factor /= 2;
                        }

                        //
                        //      (6) Inflict the damage.
                        //

                        damage = victim->receive_damage("qi", damage, me );

                        if( random(damage) > (int)victim->query_temp("apply/armor")
                        && ( (me->is_killing(victim->query("id")))
                                && ((!weapon) && !random(4) || weapon && !random(2) )
                            || ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
                        {
                                // We are sure that damage is greater than victim's armor here.
                                victim->receive_wound("qi",
                                        damage - (int)victim->query_temp("apply/armor"), me);
                                wounded = 1;
                        }

                        result += damage_msg(damage, action["damage_type"]);

                                 //
                        //      (7) Give experience
                        //

                        if( !userp(me) || !userp(victim) ) {
                                if( (ap < dp)
                                &&      (random(my["jing"]*100/my["max_jing"] + my["int"]) > 30) ) {
                                        my["combat_exp"] += 1;
                                        if ( my["potential"] - my["learned_points"] < potential_lv(my["combat_exp"]) )
                                                my["potential"] += 1;
                                        me->improve_skill(attack_skill, 1);
                                }
                                if( random(your["max_qi"] + your["qi"]) < damage ) {
                                        your["combat_exp"] += 1;
                                        if ( your["potential"] - your["learned_points"] < potential_lv(my["combat_exp"]) )
                                                your["potential"] += 1;
                                }
                        }
                }
        }

        result = replace_string( result, "$l", limb );
        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );
        else if( attack_skill == "finger" )
                result = replace_string( result, "$w", "���ξ���" );
        else if( attack_skill == "strike" )
                result = replace_string( result, "$w", "���ξ���" );
        message_vision(result, me, victim );

        result = replace_string(result,  "$P", me->name());
        result = replace_string(result,  "$N", me->name());
        result = replace_string(result,  "$n", victim->name());
        result = replace_string(result,  "$p", victim->name());

        if ((string)environment(me)->query("short") == "��̨")
        for (userno=0; userno<sizeof(player); userno++)
                if (player[userno]->query_temp("view_leitai"))
                        tell_object(player[userno], result);

        if( (string)me->query("env/combat") ) {
                if( damage > 0 )
                        tell_object(me, sprintf( HIW "AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR,
                                ap/100, dp/100, pp/100, damage));
                else
                        tell_object(me, sprintf( HIW "AP��%d��DP��%d��PP��%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }
        if( (string)victim->query("env/combat")) {
                if( damage > 0 )
                        tell_object(victim, sprintf( HIW "AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR,
                                ap/100, dp/100, pp/100, damage));
                else
                        tell_object(victim, sprintf( HIW "AP��%d��DP��%d��PP��%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }
        if( damage > 0 ) {
                report_status(victim, wounded);
                if( victim->is_busy() ) victim->interrupt_me(me);
                if( (!me->is_killing(your["id"])) &&
                (!victim->is_killing(my["id"])) &&
                victim->query("qi")*2 <= victim->query("max_qi")) {
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
                        message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
// �����ֳ�ת�� start
                result = winner_msg[random(sizeof(winner_msg))];
                result = replace_string(result,  "$P", me->name());
                result = replace_string(result,  "$N", me->name());
                result = replace_string(result,  "$n", victim->name());
                result = replace_string(result,  "$p", victim->name());
                if ((string)environment(me)->query("short") == "��̨")
                        for (userno=0; userno<sizeof(player); userno++)
                                if (player[userno]->query_temp("view_leitai"))
                                        tell_object(player[userno], result);
// �����ֳ�ת�� end
                }
        }
        if( functionp(action["post_action"]) )
                evaluate( action["post_action"], me, victim, weapon, damage);

        // See if the victim can make a riposte.
        if( attack_type==TYPE_REGULAR
        &&      damage < 1
        &&      victim->query_temp("guarding") ) {
                victim->set_temp("guarding", 0);
                if( random(my["dex"]) < 5 ) {
                        message_vision("$Nһ�����У�¶����������\n", me);
// �����ֳ�ת�� start
                        if ((string)environment(me)->query("short") == "��̨")
                        for (userno=0; userno<sizeof(player); userno++)
                                if (player[userno]->query_temp("view_leitai"))
                                        tell_object(player[userno], me->name()+"һ�����У�¶����������\n");
// �����ֳ�ת�� end
                        do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
                } else {
                        message_vision("$N��$n����ʧ�󣬳û�����������\n", victim, me);
// �����ֳ�ת�� start
                        if ((string)environment(me)->query("short") == "��̨")
                        for (userno=0; userno<sizeof(player); userno++)
                                if (player[userno]->query_temp("view_leitai"))
                                        tell_object(player[userno], me->name()+"��"+victim->name()+"����ʧ�󣬳û�����������\n");
// �����ֳ�ת�� end
                        do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
                }
        }
}

//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
        string result;

// �����ֳ�ת�� start
        player=users();
// �����ֳ�ת�� end

        if( !living(me) ) return;

// If victim is busy or unconcious, always take the chance to make an attack.
        if( victim->is_busy() || !living(victim) ) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

                if( me->is_fighting(victim) && victim->is_fighting(me))
                if( (!objectp(me->query_temp("weapon"))
                   && sizeof(me->query_skill_prepare()) > 1)
                ||  ( objectp(me->query_temp("weapon"))
                   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
                   && me->query_skill("pixie-jian", 1) >= 100
                   && me->query_skill_mapped("sword") == "pixie-jian") )
                {
                   me->set_temp("action_flag",1);
                   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                   me->set_temp("action_flag",0);
                }

        // Else, see if we are brave enough to make an aggressive action.
        } else if( random( (int)victim->query_dex() * 3 ) > (int)me->query_str()) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

                if( me->is_fighting(victim) && victim->is_fighting(me))
                if( (!objectp(me->query_temp("weapon"))
                   && sizeof(me->query_skill_prepare()) > 1)
                ||  ( objectp(me->query_temp("weapon"))
                   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
                   && me->query_skill("pixie-jian", 1) >= 100
                   && me->query_skill_mapped("sword") == "pixie-jian") )
                {
                me->set_temp("action_flag",1);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
                me->set_temp("action_flag",0);
                }

        // Else, we just start guarding.
        } else if( !me->query_temp("guarding") ) {
                me->set_temp("guarding", 1);
                message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
// �����ֳ�ת�� start
                result = guard_msg[random(sizeof(guard_msg))];
                result = replace_string(result,  "$P", me->name());
                result = replace_string(result,  "$N", me->name());
                       result = replace_string(result,  "$n", victim->name());
                result = replace_string(result,  "$p", victim->name());
                if ((string)environment(me)->query("short") == "��̨")
                for (userno=0; userno<sizeof(player); userno++)
                        if (player[userno]->query_temp("view_leitai"))
                                tell_object(player[userno], result);
// �����ֳ�ת�� end
                return;
        } else return;
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
        // Don't let NPC autofight NPC.
        if( !userp(me) && !userp(obj) ) return;

        // Because most of the cases that we cannot start a fight cannot be checked
        // before we really call the kill_ob(), so we just make sure we have no
// aggressive callout wating here.
        if( me->query_temp("looking_for_trouble") ) return;
        me->set_temp("looking_for_trouble", 1);

        // This call_out gives victim a chance to slip trough the fierce guys.
        call_out( "start_" + type, 0, me, obj);
}
void start_berserk(object me, object obj)
{
        int shen;

        if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        shen = (int)me->query("shen");
              if(shen < 0)
                shen = 0 - shen;
        message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

        if( !userp(me) || (int)me->query("neili") > (random(shen) + shen) / 2 )
                return;

// Modified by Hop
        if( shen > ((int)me->query("neili") * 5)
        &&      !wizardp(obj) ) {
                message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
                        + "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
                me->kill_ob(obj);
        } else {
                message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
                        + "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
                        me, obj);
                me->fight_ob(obj);
        }
}

void start_hatred(object me, object obj)
{
 if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We found our hatred! Charge!
        message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
        me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
        if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
          ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We found our vendetta opponent! Charge!
        me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
        if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We got a nice victim! Kill him/her/it!!!
        me->kill_ob(obj);
}
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
// �����ֳ�ת�� start
        player=users();
// �����ֳ�ת�� end
        switch(event) {
                case "dead":
message_vision( NOR"\n$N���ڵ��������˼��£������������"HIR"��Ѫ"NOR"�����ˣ�\n\n" NOR, ob);
// �����ֳ�ת�� start
                        if ((string)environment(ob)->query("short") == "��̨")
                        for (userno=0; userno<sizeof(player); userno++)
                                if (player[userno]->query_temp("view_leitai"))
                                        tell_object(player[userno], "\n"+ob->name()+"���ڵ��������˼��£���һ�ţ������������"HIR"��Ѫ"NOR"�����ˡ�\n");
// �����ֳ�ת�� end
                        break;
                case "unconcious":
                        message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
// �����ֳ�ת�� start
                        if ((string)environment(ob)->query("short") == "��̨")
                        for (userno=0; userno<sizeof(player); userno++)
                                if (player[userno]->query_temp("view_leitai"))
                                        tell_object(player[userno], "\n"+ob->name()+"����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n");
// �����ֳ�ת�� end
                        break;
                case "revive":
                        message_vision("\n$N���������۾��������˹�����\n\n", ob);
// �����ֳ�ת�� start
                        if ((string)environment(ob)->query("short") == "��̨")
                        for (userno=0; userno<sizeof(player); userno++)
                                if (player[userno]->query_temp("view_leitai"))
                                        tell_object(player[userno], "\n"+ob->name()+"���������۾��������˹�����\n\n");
// �����ֳ�ת�� end
                        break;
        }
}
void winner_reward(object killer, object victim)
{
        killer->defeated_enemy(victim);
}
void killer_reward(object killer, object victim)
{
        int bls;
        string vmark;
        mapping quest, actions;
          string msg="���ˣ��������ĺ����档";

        int exp, amount, pot, score, bonus,factor;
              object money;

// Call the mudlib killer apply.
        killer->killed_enemy(victim);

//add by angle 

             if (userp(killer) && killer->query_temp("kill_killer"))
                    {
                      killer->add("combat_exp",(int)victim->query("combat_exp")/10);
                      killer->add("score",(int)victim->query("score")/10);
                                       amount = killer->query_temp("kill_killer");
                                       money = new("/clone/money/gold");
                           money->set_amount((random(5)+1) * killer->query_temp("kill_killer") );
                           money->move(killer);
                           CHANNEL_D->do_channel(this_object(), "rumor",
sprintf("%s���ٸ�ͨ����%s�͵�������������������ŵ����⽱��!",killer->name(),victim->name()));
                      killer->clear_condition("killer");
                      killer->delete_temp("kill_killer");
                      victim->clear_condition("killer");
            }

        else if( userp(victim) ) {
                killer->add("PKS", 1);
                victim->clear_condition();
                // Give the death penalty to the dying user.
                victim->add("shen", -(int)victim->query("shen") / 10);
                victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
                victim->delete("vendetta");
//����������¼��������������  zyx
                victim->add("kill/killer_die",1);
                victim->set("kill/killer_name",killer->query("name"));
                victim->set("kill/killer_date",ctime(time()) );

                if( victim->query("thief") )
                        victim->set("thief", (int)victim->query("thief") / 2);
                if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                        victim->add("potential",
((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
                victim->skill_death_penalty();
// Add by jungu
                if (userp(killer))
write_file("/log/static/KILL_PLAYER",sprintf("%s(%s) killed by %s(%s) on %s\n",
                victim->name(1), victim->query("id"),
                killer->name(1),killer->query("id"),ctime(time()) ));
// End of apprendence

                // Look for PKS
                bls = 10;
/*
                CHANNEL_D->do_channel(this_object(), "rumor",
// This line is modefied by Hop, 97.05.16
// After the modification, if you kill a player with mask on face,
// the rumor channel will not display your real name.
                        sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(0)));
if ( userp(killer) && !killer->query_temp("kill_killer")) {
                                CHANNEL_D->do_channel(this_object(), "rumor",
                                sprintf("%s���ٸ�ͨ���ˡ�", killer->name(0)));
                        }
        } else {
                killer->add("MKS", 1);
                bls = 1;
 }
*/
// by rhxlwd
                if(objectp(killer))
                {
                        msg="��"+killer->name();
                        actions = killer->query("actions");
                        switch(actions["damage_type"]) {
                        case "����":
                        case "����":
                                msg+="�����ˣ�";
                                break;
                        case "����":
                                msg+="�����ˣ�";
                                break;
                        case "����":
                                msg+="�����ˣ�";
                                break;
                        case "����":
                                msg+="�����ˣ�";
                                break;
                        default:
                                msg+="ɱ���ˣ�";
                        }
                }
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("��˵%s"+msg+"���ǲҲ��̶ð���", victim->name(1)));
                if ( userp(killer) && !killer->query_temp("kill_killer")) {
                                CHANNEL_D->do_channel(this_object(), "rumor",
                                sprintf("%s���ٸ�ͨ���ˡ�", killer->name(0)));
                        }
                write_file("/log/static/KILLRECORD",sprintf("%s   ɱ����   %s on %s\n", killer->name(1),victim->name(1), ctime(time()) ));
        } else {
                killer->add("MKS", 1);
                bls = 1;
        }

        if (userp(killer) && killer->query("combat_exp") < victim->query("combat_exp"))
                killer->add("shen", -(int)victim->query("shen") / 10);
//Add by Brave
//�ж�ʦ���ҳ϶�
        if(userp(killer) && killer->query("family") &&
        killer->query("family/family_name") == victim->query("family/family_name"))
{
                killer->add("score",-victim->query("combat_exp")*50/(1+killer->query("combat_exp")));
                if(victim->query("combat_exp")*50/(1+killer->query("combat_exp"))>0)
                        tell_object(killer,HIR"������к�ͬ�ţ����ʦ���ҳ϶Ƚ����ˣ���\n"NOR);
        }
/*
        else if (!wizardp(killer) && !wizardp(victim) &&
                killer->query("family") && victim->query("family") )
                compare(killer,victim);
*/
// Added by Hop
// Player-killer will be wanted by soldiers, and if killer & victim are all players,
// the killer will gain some exp from victim. But it has some limit of cause.
        if (userp(victim) && userp(killer))
                killer->apply_condition("killer", 1000);

/*
  if (userp(killer) && (((int)killer->query("combat_exp") * 2) < (int)victim->query("combat_exp") )
        && userp(victim) && ((int)victim->query("combat_exp") >= 50000) )
                killer->add("combat_exp", (int)victim->query("combat_exp") / 30);
*/
// End of appendence
        if( stringp(vmark = victim->query("vendetta_mark")) )
                killer->add("vendetta/" + vmark, 1);

// add the quest reward here

        if (userp(victim))
        {
                return;
        }
        if( interactive(killer) && (quest = killer->query("mpquest"))
                && ( (int)killer->query("task_time") >= time())
                &&(quest["quest"]==victim->query("name")))
        {
                tell_object(killer,HIW"��ϲ�㣡���������һ������\n"NOR);
                score = quest["score"] + random(quest["score"]);
                tell_object(killer,HIW"���"+killer->query("family/family_name")+
                        "���ҳ϶������"+chinese_number(score)+"�㡣\n"NOR);
                if(!killer->query("score"))
        killer->set("score",0);
                killer->add("score",score);
                killer->delete("mpquest");
        }

        if( interactive(killer) && (quest = killer->query("quest"))
                && ( (int)killer->query("task_time") >= time())
                &&(quest["quest"]==victim->query("name")))
{
                tell_object(killer,"��ϲ�㣡���������һ������\n");
                exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
                pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
                factor=victim->query("quest_factor");
                if (factor)
                {
                        exp=exp*factor/10;
                        pot=pot*factor/10;
                        score=score*factor/10;
                }
                bonus = (int) killer->query("combat_exp");
                bonus += exp;
                killer->set("combat_exp", bonus);
                bonus = (int) killer->query("potential");
        bonus = bonus - (int) killer->query("learned_points");
                bonus = bonus + pot;
                if ( bonus > potential_lv((int)killer->query("combat_exp")) )
                bonus = potential_lv((int)killer->query("combat_exp"));
                bonus += (int)killer->query("learned_points");
                killer->set("potential", bonus );
                bonus = (int)killer->query("shen");
                killer->set("shen", bonus);
tell_object(killer,HIW"�㱻�����ˣ�\n" +
                chinese_number(exp) + "��ʵս����\n"+
                chinese_number(pot) + "��Ǳ��\n" +
                  chinese_number(score)+"����\n"
                        NOR     );
                killer->set("quest", 0 );
        }
}
/*
void compare(object killer,object victim)
{
        int score,mp_num;
        string allstr;
        string str,pai,pai2,pai3;
        int i,k;
             if(!(score=victim->query("score")))
                score=victim->query("combat_exp")/200+1;
        if(score<100)return;
        pai  = killer->query("family/family_name");
        pai2 = victim->query("family/family_name");
        str=read_file("/hate/mp_num",1,1);
        sscanf(str,"%d",mp_num);
        str = "";
for(i=0;i<mp_num-1;i++)
        {
                allstr = "";
                pai3 = "";
                allstr = read_file("/hate/"+pai2,i+1,1);
                sscanf(allstr,"%s %d",pai3,k);
                if ( pai3 == pai)
                {
                        if(k>-1000)
                        {
                                if(score>5000)
                                score=5000;
                                k-=score/200+1;
                        }
                        allstr = "";
                        allstr = pai3+" "+k+"\n";
                }
                str += allstr;
        }
        write_file("/hate/"+pai2, str, 1);
        tell_object(killer,HIR"������к�"+victim->query("name")+
               "��"+victim->query("family/family_name")+"�����ʦ�Ÿ��ӳ����ˣ�\n"NOR);
        return;
}
*/
void victim_penalty(object victim)
{
        victim->clear_condition();
        victim->add("shen", -(int)victim->query("shen") / 10);
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
        victim->delete("vendetta");
        if ( victim->query("thief") )
                victim->set("thief", (int)victim->query("thief") / 2);
        if ( (int)victim->query("potential") > (int)victim->query("learned_points"))
                victim->add("potential",
                        ((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
        victim->skill_death_penalty();
}
int potential_lv(int exp)
{
        int grade;

        grade = 100 + exp / 500;
        return grade;
}
