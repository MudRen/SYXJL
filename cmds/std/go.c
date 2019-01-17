// go.c write by Ronger 11/98

#include <ansi.h>
#define TIME_CHECK NATURE_D->outdoor_room_description()

inherit F_CLEAN_UP;

mapping default_dirs1 = ([
	"north":                "����",
	"south":                "����",
	"east":                 "����",
	"west":                 "����",
	"northup":              "����",
	"southup":              "�ϱ�",
	"eastup":               "����",
	"westup":               "����",
	"northdown":            "����",
	"southdown":            "�ϱ�",
	"eastdown":             "����",
	"westdown":             "����",
	"northeast":            "����",
	"northwest":            "����",
	"southeast":            "����",
	"southwest":            "����",
	"up":                   "����",
	"down":                 "����",
	"enter":                "����",
	"out":                  "����",
]);
mapping default_dirs2 = ([
	"north":                "����",
	"south":                "����",
	"east":                 "����",
	"west":                 "����",
	"northup":              "�ϱ�",
	"southup":              "����",
	"eastup":               "����",
	"westup":               "����",
	"northdown":            "�ϱ�",
	"southdown":            "����",
	"eastdown":             "����",
	"westdown":             "����",
	"northeast":            "����",
	"northwest":            "����",
	"southeast":            "����",
	"southwest":            "����",
	"up":                   "����",
	"down":                 "����",
	"enter":                "����",
	"out":                  "����",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir1, dir2, dir3, dir4;
	object env, env1, obj;
	mapping exit;

	object *f_obs, *ob;
	int count = 0, my_dex, i;
//       int costj = random((int)me->query("con")/10)+1;
	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <=
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
			message_vision("$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ�û��ô���ף�\n", me, f_obs[0]);
			return notify_fail("������ʧ�ܡ�\n");
		}
	}
//77
	env = environment(me);
	exit = env->query("exits");
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("�������û�г�·��\n");
		else
			return 0;
	}

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("�޷��ƶ���\n");

	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i] != me )
			count++;
	my_dex = (int)me->query_dex();
	if(((my_dex < 15) && (count > 8))
	|| ((my_dex < 20) && (count > 10))
	|| ((my_dex < 30) && (count > 12))
	|| ((my_dex < 40) && (count > 14)))
		return notify_fail("ǰ����̫���ˣ�����ô��Ҳ������ȥ��\n");
	if (me->query("water") == 0 && me->query("foot") == 0)
		    me->add("jing", -(2+random(2)));
	if ( me->query("jing") <= 8 )
		return notify_fail("���Ѿ�û����������·�ˣ���Ϣһ�°ɡ�\n");

	if( !env->valid_leave(me, arg) ) return 0;

//added by Ronger
	env1 = find_object(exit[arg]);
	dir3 =(string)env1->query("short");
	dir4 =(string)env->query("short");
	if( !undefinedp(default_dirs1[arg]) && !undefinedp(default_dirs2[arg]))
	{
		dir1 = default_dirs1[arg];
		dir2 = default_dirs2[arg];
	}
	else
	{
		dir1 = arg;
		dir2 = arg;
	}
	if ( (strsrch(TIME_CHECK, "ҹ��") != -1 || strsrch(TIME_CHECK, "��ҹ") != -1) && env->query("outdoors") )
	{
		if( me->is_fighting() )
		{
			if ( wizardp(me) )
			{
				mout = "";
				min = "";
			}
			else {
				mout = "һ����Ӱ��" + dir1 + "��"HIC + dir3 + NOR"��Ķ����ˡ�\n";
				min = "һ����Ӱ����ײײ�ش�" + dir2 + "��"HIC + dir4 + NOR"���˹�����ģ����Щ�Ǳ���\n";
			}
		}
		else
		{
			if ( wizardp(me) )
			{
				mout = "";
				min = "";
			}
			else
			{
				mout = "һ����Ӱ��" + dir1 + "�뿪�ˡ�\n";
				min = "һ����Ӱ���˹�����\n";
			}
		}
	}
	else {
		if ( !me->query_temp("armor/cloth") && me->query("race")=="����" )
		{
			if( me->is_fighting() )
			{
				if ( wizardp(me) )
				{
					mout = "";
					min = "";
				}
				else {
					mout = me->name() +"����"YEL"����"NOR"��" + dir1 + "��"HIC + dir3 + NOR"��Ķ����ˡ�\n";
					min = me->name() + "����"YEL"����"NOR"����ײײ�ش�" + dir2 + "��"HIC + dir4 + NOR"���˹�����ģ����Щ�Ǳ���\n";
				}
			}
			else
			{
				if ( wizardp(me) )
				{
					mout = "";
					min = "";
				}
				else
				{
					mout = me->name() + "����"YEL"����"NOR"��" + dir1 + "��"HIC + dir3 + NOR"�뿪�ˡ�\n";
					min = me->name() +"����"YEL"����"NOR"��" + dir2 + "��"HIC + dir4 + NOR"���˹�����\n";
				}
			}
		}
		else
		{
			if( me->is_fighting() )
			{
				if ( wizardp(me) )
				{
					mout = "";
					min = "";
				}
				else {
					mout = me->name() + "��" + dir1 + "��"HIC + dir3 + NOR"��Ķ����ˡ�\n";
					min = me->name() + "����ײײ�ش�" + dir2 + "��"HIC + dir4 + NOR"���˹�����ģ����Щ�Ǳ���\n";
				}
			}
			else
			{
				if ( wizardp(me) )
				{
					mout = "";
					min = "";
				}
				else
				{
					mout = me->name() + "��" + dir1 + "��"HIC + dir3 + NOR"�뿪�ˡ�\n";
					min = me->name() +"��" + dir2 + "��"HIC + dir4 + NOR"���˹�����\n";
				}
			}
		}
	}

//end
	message( "vision", mout, environment(me), ({me}) );
/*
	if (!wizardp(me)&&!me->query_temp("armor/boots") && me->query("race")=="����" )   
	{
		me->receive_damage("jing", costj*2);   		
                message_vision("$N���Ž��ڵ�����·���е��������ĵ��ۡ�\n",me);              
	}	
*/	
/*
	if ( !wizardp(me) )	
       		me->receive_damage("jing", costj);		
*/
	if( me->move(obj) ) {
		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "�������һ���������...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : go <����>

������ָ���ķ����ƶ���

HELP
    );
    return 1;
}
