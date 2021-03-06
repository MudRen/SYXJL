// goto.c

// writed by shadow



#include <ansi.h>

inherit F_CLEAN_UP;



int main(object me, string arg)

{

	int goto_inventory = 0,opt_nomessage = 0;

	object obj;

	string msg;



	if( !arg ) return notify_fail("你要去哪里？\n");



	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;



	if( sscanf(arg, "-n %s", arg) ) opt_nomessage = 1;



	if( !arg ) return notify_fail("你要去哪里？\n");



	obj = find_player(arg);

	if(!obj) obj = find_living(arg);

	if(!obj || !me->visible(obj))

	{

		arg = resolve_path(me->query("cwd"), arg);

		if( !sscanf(arg, "%*s.c") ) arg += ".c";

		if( !(obj = find_object(arg)) )

		{

			if( file_size(arg)>=0 )	return me->move(arg);

			return notify_fail("没有这个玩家、生物、或地方。\n");

		}

	}



	if(!goto_inventory && environment(obj))

		obj = environment(obj);



	if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");



		if ( (string)me->query("env/msg_mout") =="none")

			message_vision("",me);

	if ( !opt_nomessage )

	{

		if( stringp(msg = me->query("env/msg_mout")) )

			message_vision(msg+"\n", me);

		else

			message_vision(CYN"只见一阵烟雾过後，$N的身影已经不见了。\n"NOR, me);

	}



	me->move(obj);



		if ( (string)me->query("env/msg_mout") =="none")

			message_vision("",me);

	if ( !opt_nomessage )

	{

		if( stringp(msg = me->query("env/msg_min")) )

			message_vision(msg+"\n", me);

		else

			message_vision(CYN"$N的身影突然出现在一阵烟雾之中。\n"NOR, me);

	}



	return 1;

}



int help(object me)

{

write(@HELP

指令格式 : goto [-i|-n] <目标>

 

这个指令会将你传送到指定的目标. 目标可以是一个living 或房间

的档名. 如果目标是living , 你会被移到跟那个人同样的环境.

如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的

的 inventory 中,加上 -n 参数移动时不显示信息。

 

HELP

    );

    return 1;

}

