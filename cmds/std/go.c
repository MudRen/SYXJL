// go.c write by Ronger 11/98

#include <ansi.h>
#define TIME_CHECK NATURE_D->outdoor_room_description()

inherit F_CLEAN_UP;

mapping default_dirs1 = ([
	"north":                "北面",
	"south":                "南面",
	"east":                 "东面",
	"west":                 "西面",
	"northup":              "北边",
	"southup":              "南边",
	"eastup":               "东边",
	"westup":               "西边",
	"northdown":            "北边",
	"southdown":            "南边",
	"eastdown":             "东边",
	"westdown":             "西边",
	"northeast":            "东北",
	"northwest":            "西北",
	"southeast":            "东南",
	"southwest":            "西南",
	"up":                   "上面",
	"down":                 "下面",
	"enter":                "里面",
	"out":                  "外面",
]);
mapping default_dirs2 = ([
	"north":                "南面",
	"south":                "北面",
	"east":                 "西面",
	"west":                 "东面",
	"northup":              "南边",
	"southup":              "北边",
	"eastup":               "西边",
	"westup":               "东边",
	"northdown":            "南边",
	"southdown":            "北边",
	"eastdown":             "西边",
	"westdown":             "东边",
	"northeast":            "西南",
	"northwest":            "东南",
	"southeast":            "西北",
	"southwest":            "东北",
	"up":                   "下面",
	"down":                 "上面",
	"enter":                "外面",
	"out":                  "里面",
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
	if( !arg ) return notify_fail("你要往哪个方向走？\n");

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <=
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
			message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？没那么容易！\n", me, f_obs[0]);
			return notify_fail("你逃跑失败。\n");
		}
	}
//77
	env = environment(me);
	exit = env->query("exits");
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");

	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i] != me )
			count++;
	my_dex = (int)me->query_dex();
	if(((my_dex < 15) && (count > 8))
	|| ((my_dex < 20) && (count > 10))
	|| ((my_dex < 30) && (count > 12))
	|| ((my_dex < 40) && (count > 14)))
		return notify_fail("前面人太多了，你怎么挤也挤不过去。\n");
	if (me->query("water") == 0 && me->query("foot") == 0)
		    me->add("jing", -(2+random(2)));
	if ( me->query("jing") <= 8 )
		return notify_fail("你已经没有力气再走路了，休息一下吧。\n");

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
	if ( (strsrch(TIME_CHECK, "夜晚") != -1 || strsrch(TIME_CHECK, "深夜") != -1) && env->query("outdoors") )
	{
		if( me->is_fighting() )
		{
			if ( wizardp(me) )
			{
				mout = "";
				min = "";
			}
			else {
				mout = "一条黑影往" + dir1 + "的"HIC + dir3 + NOR"落荒而逃了。\n";
				min = "一条黑影跌跌撞撞地从" + dir2 + "的"HIC + dir4 + NOR"跑了过来，模样有些狼狈。\n";
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
				mout = "一条黑影往" + dir1 + "离开了。\n";
				min = "一条黑影走了过来。\n";
			}
		}
	}
	else {
		if ( !me->query_temp("armor/cloth") && me->query("race")=="人类" )
		{
			if( me->is_fighting() )
			{
				if ( wizardp(me) )
				{
					mout = "";
					min = "";
				}
				else {
					mout = me->name() +"光着"YEL"身子"NOR"往" + dir1 + "的"HIC + dir3 + NOR"落荒而逃了。\n";
					min = me->name() + "光着"YEL"身子"NOR"跌跌撞撞地从" + dir2 + "的"HIC + dir4 + NOR"跑了过来，模样有些狼狈。\n";
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
					mout = me->name() + "光着"YEL"身子"NOR"往" + dir1 + "的"HIC + dir3 + NOR"离开了。\n";
					min = me->name() +"光着"YEL"身子"NOR"从" + dir2 + "的"HIC + dir4 + NOR"走了过来。\n";
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
					mout = me->name() + "往" + dir1 + "的"HIC + dir3 + NOR"落荒而逃了。\n";
					min = me->name() + "跌跌撞撞地从" + dir2 + "的"HIC + dir4 + NOR"跑了过来，模样有些狼狈。\n";
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
					mout = me->name() + "往" + dir1 + "的"HIC + dir3 + NOR"离开了。\n";
					min = me->name() +"从" + dir2 + "的"HIC + dir4 + NOR"走了过来。\n";
				}
			}
		}
	}

//end
	message( "vision", mout, environment(me), ({me}) );
/*
	if (!wizardp(me)&&!me->query_temp("armor/boots") && me->query("race")=="人类" )   
	{
		me->receive_damage("jing", costj*2);   		
                message_vision("$N赤着脚在地上走路，感到两脚钻心地疼。\n",me);              
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
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>

让你往指定的方向移动。

HELP
    );
    return 1;
}
