// damage.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;

int is_ghost() { return ghost; }

void set_ghost(int g) { ghost=g; }  // add by hello 96.10.22

varargs int receive_damage(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
        if( type!="jing" && type!="qi" )
                error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

        if( objectp(who) ) set_temp("last_damage_from", who);
        val = (int)query(type) - damage;

        if( val >= 0 ) set(type, val);
        else set( type, -1 );

        set_heart_beat(1);

        return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
        if( type!="jing" && type!="qi" )
                error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

        if( objectp(who) ) set_temp("last_damage_from", who);
        val = (int)query("eff_" + type) - damage;

        if( val >= 0 ) set("eff_" + type, val);
        else {
                set( "eff_" + type, -1 );
                val = -1;
        }

        if( (int)query(type) > val ) set(type, val);

        set_heart_beat(1);

        return damage;
}

int receive_heal(string type, int heal)
{
        int val;

        if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
        if( type!="jing" && type!="qi" )
                error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

        val = (int)query(type) + heal;

        if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
        else set( type, val );

        return heal;
}

int receive_curing(string type, int heal)
{
        int max, val;

        if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
        if( type!="jing" && type!="qi" )
                error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

        val = (int)query("eff_" + type);
        max = (int)query("max_" + type);

        if( val + heal > max ) {
                set("eff_" + type, max);
                return max - val;
        } else {
                set( "eff_" + type, val + heal);
                return heal;
        }
}

void unconcious()
{
        object ob;
        object defeater;

        if( !living(this_object()) ) return;
        if( wizardp(this_object()) && query("env/immortal") ) return;

        if (ob = query_temp("competition"))
        {
                ob->win();
                this_object()->lost();
        }
        if( objectp(defeater = query_temp("last_damage_from")) )
                COMBAT_D->winner_reward(defeater, this_object());

        this_object()->remove_all_enemy();

        message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,
                this_object());
        this_object()->disable_player(" <���Բ���>");
        set("jing", 0);
        set("qi", 0);
        set_temp("block_msg/all", 1);
        COMBAT_D->announce(this_object(), "unconcious");

        call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
        remove_call_out("revive");
        while( environment()->is_character() )
                this_object()->move(environment(environment()));
        this_object()->enable_player();
        if( !quiet ) {
                COMBAT_D->announce(this_object(), "revive");
                set_temp("block_msg/all", 0);
                message("system", HIY "\n������������������֪��....\n\n" NOR,
                        this_object());
        } else
                set_temp("block_msg/all", 0);
}

void die()
{
        object corpse, killer;
        string str;
        object me=this_object();
        object ob;

        if( !living(this_object()) ) revive(1);
        if( wizardp(this_object()) && query("env/immortal") ) return;
        if (ob = query_temp("competition"))
        {
                ob->win();
                this_object()->lost();
        }

        if(environment(this_object())->query("short")=="��֮��̨") {
                me->set("qi", 1);
                me->set("jing", 1);
                if(me->query("eff_jing") < 1)
                        me->set("eff_jing", 1);
                if(me->query("eff_qi") < 1)
                        me->set("eff_qi", 1);

                me->remove_all_killer();
                all_inventory(environment(me))->remove_killer(me);

                if(!userp(me)) {
                        message_vision("\n$N���ص�ˤ���ڵأ��ŵ�����æ��$N����\n",me);
                        destruct(me);
                        return;
                }
                else message_vision("\n$N���ص�ˤ���ڵأ�����ʦ��æ����������������\n",me);
                message_vision("���´�����������������ˮ½�����䣬�������٣�\n",me);
                message_vision("\n$N��ΡΡ�شӵ���վ��������\n",me);
                return;
        }
        // Clear all the conditions by death.
        this_object()->clear_condition();

        COMBAT_D->announce(this_object(), "dead");

        if ( objectp(killer = query_temp("last_damage_from")) )
        {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
        }
        else
        {
                //no obvious killer. by mon 8/17/97
                //for example, by poison.
                if( userp(this_object()) && !wizardp(this_object()) )
                {
                        COMBAT_D->victim_penalty(this_object());
                        if (str=this_object()->query_temp("death_msg"))
                                str=this_object()->name(1)+str;
                          else  str=this_object()->name(1)+"���ˣ��������ĺ����档\n";
                        COMBAT_D->announce(this_object(), "death_rumor", str);
                          message("channel:rumor", HIM +"���������š�ĳ�ˣ���˵" + this_object()->name(1) +
                                  "���ˣ��������ĺ����档\n" NOR, users());
                }
        }

        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());

        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        if( userp(this_object()) ) {
                if (this_object()->is_busy())
                        this_object()->interrupt_me();
                set("jing", 1); set("eff_jing", 1);
                set("qi", 1);   set("eff_qi", 1);
                ghost = 1;
                this_object()->move(DEATH_ROOM);
                DEATH_ROOM->start_death(this_object());
        } else
                destruct(this_object());
}

void reincarnate()
{
        ghost = 0;
        set("eff_jing", query("max_jing"));
        set("eff_qi", query("max_qi"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
        int update_flag, i;
        object me = this_object();
        mapping my;

        update_flag = 0;

        my = query_entire_dbase();
        if (query_temp("nopoison"))
                delete_temp("nopoison");
        if( my["water"] > 0 ) { my["water"]--; update_flag++; }
        if( my["food"] > 0 ) { my["food"]--; update_flag++; }

        if( my["water"] < 1 && userp(me) && !wizardp(me)) {
                message_vision("$N�ʵ���ð���ǣ�ȫ��������\n", me);
// me->start_busy(1);
                return update_flag;
        }
        
        i = my["con"] / 3 + my["max_jingli"] / 10;
        if (me->is_fighting()) i /= 3;
        my["jing"] += i;
        if( my["jing"] >= my["eff_jing"] ) {
                my["jing"] = my["eff_jing"];
                if( my["eff_jing"] < my["max_jing"] ) { my["eff_jing"]++; update_flag++; }
        } else update_flag++;

        i = my["con"] / 3 + my["max_neili"] / 10;
        if (me->is_fighting()) i /= 3;
        my["qi"] += i;
        if( my["qi"] >= my["eff_qi"] ) {
                my["qi"] = my["eff_qi"];
                if( my["eff_qi"] < my["max_qi"] ) { my["eff_qi"]++; update_flag++; }
        } else update_flag++;
	if( my["douzhi"] < my["eff_douzhi"] ) 
	{
		 my["douzhi"] ++; update_flag++; 
	}
	else update_flag++;
/*
       if ( my["kill"] > (my["combat_exp"] * my["bac"] / 50))
	{
               my["kill"] --; update_flag++;
	}        
*/
        if( my["food"] < 1 && userp(me) && !wizardp(me)) {
                message_vision("$N����ͷ���ۻ���ֻð�亹��\n", me);
// me->start_busy(1);
                return update_flag;
        }

        if( my["jingli"] < my["eff_jingli"] ) {
                i = my["con"] / 2 + me->query_skill("force", 1) / 3;
                if (me->is_fighting()) i /= 3;
                my["jingli"] += i;
                if( my["jingli"] > my["eff_jingli"] ) my["jingli"] = my["eff_jingli"];
                update_flag++;
        }

        if( my["neili"] < my["max_neili"] ) {
                i = me->query_skill("force", 1) / 2 + my["con"];
                if (me->is_fighting()) i /= 3;
                my["neili"] += i;
                if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
                update_flag++;
        }

        return update_flag;
}


void check_force()
{
	object abc;
	abc = this_object();
	if ( !living(abc) ) return;
	if ( wizardp(abc) && query("env/immortal") ) return;

	abc->remove_all_enemy();

	message( "system",
    	HIW "\nͻȻ����о������ڵ�����������ײԽ��Խ���ҡ�\n"NOR
    	HIR "��ֻ�������ڵ���ϢԽ��Խ�죬�����п��Ʋ�ס�ĸо�����\n\n" NOR
    	HIR "ǿ�ҵ���������ľ������Ĵ����ߣ��㽥����ʧȥ��֪������"NOR, abc );
	abc->disable_player("<�߻���ħ>");
	set( "jing", 0 );
	set( "qi", 0 );
	add( "max_neili", -400 );
	add( "yin", -200 );
	add( "yang", -200 );
	set( "neili", 0 );
	set_temp( "block_msg/all", 1 );
	COMBAT_D->announce( abc, "unconcious" );
}
