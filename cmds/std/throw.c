
// throwing.c

#include <ansi.h>;
inherit F_CLEAN_UP;
inherit F_COMMAND;
inherit F_DBASE;

int do_throw(object me, object ob, object victim);
int fushi_du(object me, object victim, object ob);
private int throw_result(object me, object victim, object ob);

int main(object me, string arg)
{
        string what, who, skill; 
        object ob, victim;

        seteuid(geteuid(me));

        if( !arg
        ||      sscanf(arg, "%s at %s", what, who)!=2)
                return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");

        ob = present(what, me);
        if( !ob ) return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("no_drop"))
                return notify_fail("������������뿪�㡣\n");
        if (ob->query("embedded"))
                return notify_fail("�����������ȡ��������\n");

        if (!(victim = present(who, environment(me))))
                return notify_fail("����û�����Ŀ�ꡣ\n");

        if (!victim)
                return notify_fail("���ﲢ�޴��ˣ�\n");

        if (!living(victim))
                return notify_fail("�ⲻ�ǻ��\n");

        if (victim->query("winner"))
                return notify_fail("���ɶ�"+victim->short()+"������\n");

        if (me->is_busy() )
                return notify_fail("��ǰһ��������û�����ꡣ\n");

        if (victim == me) 
                return notify_fail("�αض��һ�٣�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( !wizardp(me) && wizardp(victim) )
                return notify_fail("����Ҫ����������ͻȻ����ֻ����(rabbit)����һ�Ž����ߵ�����׼����ʦ���˲�����\n");
                
        if ( userp(me) && userp(victim) && victim->query("age") < 17 )
                return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");
        if ( userp(me) && userp(victim) && victim->query("combat_exp") < 15000 )
                return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");

        if( ob->query("weapon_prop") && me->is_exert() &&
            ob == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_exert()+"���޷��ӳ�"+ob->name()+"��\n");
        if( ob->query("weapon_prop") && me->is_perform() &&
            ob == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_perform()+"���޷��ӳ�"+ob->name()+"��\n");
                 
        if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0)
                return notify_fail("����ڽ�ֹ͵Ϯ��\n");
                
        if( ob->query("id") == "corpse" && me->query_skill("chousui-zhang", 1) >= 120 
        && me->query_skill("poison", 1) >= 120 ) 
                return fushi_du(me, victim, ob);
        
        if ( stringp(skill = ob->query("skill")) && me->query_skill(skill, 1) > 0)
                return ob->throw_ob(me, victim);

        return do_throw(me, ob, victim);
}

int do_throw(object me, object ob, object victim)
{
        string msg;

        if( !stringp(msg = ob->query("throw_msg")) )
             msg = "\n$N��һ���"+ob->name()+"��׼$n���˹�ȥ��\n";
        message_vision(msg, me, victim);

        me->start_busy(1);

        if ( victim->query_skill_mapped("sword")=="dugu-jiujian" 
        && victim->query_temp("weapon")->query("skill_type")=="sword" 
        && victim->query("combat_exp") > me->query("combat_exp")/2 ) {
                message_vision(CYN"$N�ӽ�����"+ob->name()+CYN"��ʹ�����¾Ž��ġ��Ƽ�ʽ������"+ob->name()+CYN"�����ȥ��\n"NOR, victim);                        
                throw_result(victim, me, ob);
        }
        if ( victim->query_skill_mapped("parry")=="douzhuan-xingyi" 
        && victim->query_skill("douzhuan-xingyi", 1) > 100 
        && victim->query("combat_exp") > me->query("combat_exp")/2 ) {
                message_vision(CYN"$Nʹ�����ƶ�ת����"+ob->name()+CYN"Ī�����������;ת�˷���ֱ��"+me->name()+CYN"�Լ�Ϯ����\n"NOR, victim);                        
                throw_result(victim, me, ob);
        }
        else {
                throw_result(me, victim, ob);
        }

        return 1;
}

private int throw_result(object me, object victim, object ob)
{
        string *limbs, str, dodge_skill, result;
        int ap, dp;

        ap = me->query_str()*me->query_int();
        dp = victim->query_dex()*victim->query_int();
        ap *= me->query("combat_exp")/1000;
        dp *= victim->query("combat_exp")/1000;
        ap = random(ap);

        victim->add_temp("offenders/"+me->query("id"), 1);

        if ( ap > dp/2){
                limbs = victim->query("limbs");
                victim->receive_wound("qi", me->query_str(), me);
                victim->receive_damage("qi", (ob->query_weight()/500)+me->query_str(), me);
                
                if(ob->query("embed")){
                     message_vision(CYN"���ֻ��$Nһ���ҽУ�$n"+CYN+"��Ȼ����$N��"+limbs[random(sizeof(limbs))]+"�ϡ�\n"NOR, victim, ob);
                                 ob->set("embedded", 1);
                                 ob->set("victim", victim->query("id"));
                                 ob->move(victim);
                                 ob->do_embed(victim);
                                 if(stringp(ob->query("poison"))) victim->apply_condition(ob->query("poison"), ob->query("damage")*2);
                                 victim->receive_wound("qi", me->query_str()*ob->query("damage"), me);
                                 victim->kill_ob(me);
                }
                else {  
                     message_vision(CYN"$N⧲�������$n"+CYN+"������$N��"+limbs[random(sizeof(limbs))]+"�ϡ�\n"NOR, victim, ob);
                     ob->move(environment(me));
                     if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
                     else{
                        victim->fight_ob(me);
                        call_out("do_respond", 1, victim, me);
                        }
                }
                me->start_busy(random(3));                

        result = COMBAT_D->eff_status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("($N"+result+")\n", victim);
        }

        else if ( ap < dp/7 && ob->query_weight() < 7000 
                && victim->query("race") == "����"){
                message_vision(CYN"����$N�����ֿ죬����һ�࣬��$n"+CYN+"����ؽ������\n\n"NOR, victim, ob);
                me->start_busy(random(3));
                ob->move(victim);
                if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
                else
                call_out("e_mote", 1, victim, me);      
        }

        else {

        dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                str = SKILL_D(dodge_skill)->query_dodge_msg(victim, 1);
                message_vision(str, me, victim);
                me->start_busy(random(3));
                ob->move(environment(me));
                if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
                else
                call_out("do_respond", 1, victim, me);
        }

        return 1;
}

int fushi_du(object me, object victim, object ob)
{
        int ap, dp, damage;
        string dodge_skill, str, *limbs, limb, result, type = "����";
        
        if(userp(victim) && userp(me) && (me->query_condition("pker") > 240
           || victim->query("mud_age") < 18000) )
                return notify_fail("��е�һ˿�ھΣ���ͻȻ����������\n");

        message_vision(HIB"$N���ð�ź���������ץ��"+ob->name()+"��$n��ȥ��\n"NOR, me, victim);
        
        ap = me->query_skill("strike"); 
        dp = victim->query_skill("dodge");
        ap *= me->query("combat_exp")/1000;
        dp *= victim->query("combat_exp")/1000;

        if (random(ap) > dp){
                limbs = victim->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                damage = ob->query("victim_exp")/500;
                str = COMBAT_D->damage_msg(damage, type);
                str = replace_string( str, "$l", limb); 

                victim->receive_damage("qi", damage, me);
                result = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
                message_vision(str, me, victim);
                message_vision("($N"+result+")\n", victim);

                victim->apply_condition("xx_poison", me->query_skill("poison", 1)
                        +victim->query_condition("xx_poison"));
                victim->receive_damage("qi", damage, me);
                victim->start_busy(1+random(3));
                victim->kill_ob(me);
                }
        else {
        dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                str = SKILL_D(dodge_skill)->query_dodge_msg(victim, 1);
                message_vision(str, me, victim);
                victim->kill_ob(me);
        }
        ob->move(environment(me));
        me->start_busy(1);
        return 1;
}

void e_mote(object victim, object me)
{
        int i;
        string *emote = ({
        "sneer", "callname", "consider", "killair", "grin",
        "nonsense", "walkby", "cut", "chicken", "kick", });

          if (!me || !victim || environment(me) != environment(victim))
        return;

        i = random(sizeof(emote));

        EMOTE_D->do_emote(victim, emote[i], me->query("id"));
}
        
void do_respond(object victim, object me)
{
        string att; 

        if (!me || !victim || environment(me) != environment(victim))
        return;

        att = victim->query("attitude");

        if (victim->query("shen") < 0)
                return victim->kill_ob(me);

        if (att == "friendly" && victim->query("race") == "����")
                return e_mote(victim, me);
        
        if (att == "heroism" || att == "aggressive")
                return victim->kill_ob(me);     

        if (att == "peaceful" && random(5)== 1) 
                return victim->kill_ob(me);

        else if(victim->query("race") == "����")
        EMOTE_D->do_emote(victim, "brag", me->query("id"));

        return victim->fight_ob(me);    
}
