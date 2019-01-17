// biaoyin.c

#include <ansi.h>
inherit ITEM;

int robberC;
int flagR;
int rob;
int robs;
int potential_lv(int exp);

void create()
{
	set_name( "����", ({ "biao yin", "biao","yin" }) );
	set_weight(2000+random(3000));
	set("no_put", 1);			// �����������ܷ�������
	set("identifier", random(10000));	// ȫ������ʶ���� �Ǻ�

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ھ��и������������\n");
	}

	flagR=0;
	robberC=random(11);
	robberC=(robberC<7)?7:robberC;
	rob=0;
	robs=random(2);
	robs=(robs<1)?1:robs;
}

void init()
{
	add_action("do_give", "give");
	add_action("do_go", "go");

	if( query("target") ) {
		remove_call_out("set_target");
		call_out("set_target", 4, query("target"));
		delete("target");               // add 4 seconds' delay, can't be so fast
	}
}

void set_target(string target)
{
	set("target", target);
}

int do_go(string arg)
{
	object robber, env;
	mapping exit;

	env = environment(this_player());
	exit = env->query("exits");
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) )
		return notify_fail("�������û�г�·��\n");

	if ( objectp(robber=present("mask robber", env)) ) {
		if ( robber->is_killing(this_player()->query("id")) && living(robber) && random(10) < 7 ) {
			switch(random(2)) {
				case 0:
					message_vision(HIR"\n$nһ������$N��ǰ�����ߣ��ȷ���������\n"NOR, this_player(), robber);
				break;
				case 1:
					message_vision(HIR"\n$n���Ű�$NΧס�������������£������뿪��\n"NOR, this_player(), robber);
				break;
				case 2:
					message_vision(HIR"\n$n�ȵ�����ǮҲҪ����ҲҪ�����������ˣ���\n"NOR, this_player(), robber);
				break;
			}
			return 1;
		}
	}

	flagR++;

	if( flagR == robberC && environment(this_player())->query("outdoors") && rob <= robs ) {
		if(!this_player()->is_busy())
			this_player()->start_busy(1);
		remove_call_out("attract_robber");
		call_out("attract_robber", 0);
		flagR = 0;
		robberC=random(11);
		robberC=(robberC<7)?7:robberC;
		return 1;
	}
//	write(flagR+"\n");
//	write(robberC+"\n");
	return 0;
}

int do_give(string arg)
{
        int i, bonus;
        string obj, target;
        object me, ob, home;

	if(!arg || arg==" ")
		return 0;
	if( sscanf(arg,"%s to %s", obj, target)!=2 )
		if(sscanf(arg,"%s %s", target, obj) !=2 )
			return 0;

	if( !id(obj) ) return 0;

	me = this_player();

	if(!ob = present(target,environment(me)) ) {
		tell_object(me,"����Ҫ����������˭��\n");
		return 1;
	}

	if(!ob->id(query("target")) || userp(ob)) {
		tell_object(me, "�㲻�ܰ���������������ˡ�\n");
		return 1;
        }

	if(!living(ob) ) {
		tell_object(me,ob->query("name")+"�Ѿ��޷��������������ˡ�\n");
		return 1;
	}

	if( !home = find_object(ob->query("startroom")) )
		home = load_object(ob->query("startroom"));
	if(environment(ob)!=home){
		message_vision(CYN+"$N˵������������æ���أ����һ�ȥ��˵�ɣ�"+NOR, ob);
		return 1;
	}

	message_vision("$N�ó�һ������������" + ob->query("name") + "��\n", me);
	if((time()-me->query( "yunbiao/start" ))>me->query( "yunbiao/time" ) ) {
		message_vision(CYN+"$N�������ض�$n˵������ô����¶��첻�ã���û�ã�\n"+NOR, ob, me);
		tell_object(me, "��û�м�ʱ�������͵�" + ob->query("name") + "�����У��������ʧ���ˣ�\n");
/*		i = 100 + random(time()-me->query( "yunbiao/start" )-me->query( "yunbiao/time" ))/5;
		i = i/2;
		i = (i>100)?100:i;
		me->add("combat_exp", -i);
		tell_object(me, sprintf(WHT"�㱻�۳�%s��ս�����飬\n"NOR, chinese_number(i)) );
		bonus = (int)me->query("potential");
		bonus = bonus - i/5 - 1;
		bonus = (bonus<(int)me->query("learned_points"))?(int)me->query("learned_points"):bonus;
		me->set("potential", bonus );
		tell_object(me, sprintf(WHT"%s��Ǳ�ܡ�\n"NOR, chinese_number(i/5+1)) );*/
		me->delete("yunbiao/start");
		me->delete("yunbiao/time");
		me->set("yunbiao/halt", time());
	}
        else {
                message_vision(CYN+"$N��$nЦ�����ܺã�����һ�ɵĺ���������ȥ�ɣ�\n"+NOR, ob, me);
                tell_object(me, "��ɹ��ؽ������͵���" + ob->query("name") + "�����С�\n");
                i = 100 + random(me->query( "yunbiao/time" )-time()+me->query( "yunbiao/start" ))/5;
                tell_object(me, sprintf(WHT"������%s��ս�����飬\n"NOR, chinese_number(i)) );
                me->add("combat_exp", i);
                bonus = (int)me->query("potential");
                bonus = bonus - (int)me->query("learned_points");
                bonus = bonus + i/5 + 1;
                if ( bonus > potential_lv((int)me->query("combat_exp")) )
                bonus = potential_lv((int)me->query("combat_exp"));
                bonus += (int)me->query("learned_points");
                me->set("potential", bonus );
                tell_object(me, sprintf(WHT"%s��Ǳ�ܡ�\n"NOR, chinese_number(i/5+1)) );
/*		ob=new(SILVER_OB);
                if (!ob->move(me))
			ob->move(environment(me));
		ob->add_amount(random(10)+10);*/
		me->delete("yunbiao/start");
		me->delete("yunbiao/time");
        }

        me->receive_damage("qi", 20+random(20));
        me->receive_damage("jing", 20+random(10));

        destruct(this_object());

        return 1;
}

// ����ǿ��
void attract_robber()
{
	int robbers, i;
        object ob, robber, room;

        if (!userp(ob = environment(this_object())) ) return;

	robbers = random(2);
	robbers = (robbers<1)?1:robbers;
	room = environment(ob);

	if(!objectp(present("mask robber", environment(this_player())))) {
		for(i=0; i<robbers; i++) {
			robber = new("/d/npc/robber");
			robber->set("target", query("identifier"));
			robber->set("speaker", (i==0)?1:0);
			robber->move(room);
		}
		rob++;
		message_vision("һȺ$n��·�Գ��˳�������$N����Χס��\n", ob, robber);
	}
}

void owner_is_killed() { destruct(this_object()); }

int potential_lv(int exp)
{
        int grade;

        grade = 100 + exp / 500;;
        return grade;
}
