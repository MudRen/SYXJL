// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, *ob;
	string callname;

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");

	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

	if( me->query_temp("baohuman")==obj->query("id"))
		return notify_fail(HIR "不能杀你要保护的人！\n" NOR);

	if( !obj->query_temp("begging") )
	{
		if((int)obj->query("age") <= 15 && userp(obj))
			return notify_fail("为了世界更美好，放过小孩子吧.\n");
	}

	if(!undefinedp(me->query("friends/"+obj->query("id"))))
	{
		write(HIG"你这人怎么这么坏，要杀你的好友也要先把他(她)从好友中除去！\n"NOR);
		return 1;
	}

	callname = RANK_D->query_rude(obj);

	message_vision("\n$N对著$n喝道：「"
		+ callname + "！今日不是你死就是我活！」\n\n", me, obj);

	me->kill_ob(obj);
	// Add by jungu
	if ( userp(obj))
	write_file("/log/static/ATTEMP_KILL",sprintf("%s   试图杀死   %s on %s\n",
	me->name(1),obj->name(1), ctime(time()) ));
	// Look for PKS
	if( !userp(obj) )
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name()
			+ "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
	}

	if ( (string)obj->query("family/family_name") != (string)me->query("family/family_name") ) {
		ob = all_inventory(environment(me));
		for(int i=0; i<sizeof(ob); i++) {
			if( !living(ob[i]) || ob[i]==me || ob[i]==obj || !ob[i]->query("family") ) continue;
			if( (string)ob[i]->query("family/family_name")==(string)obj->query("family/family_name") && !userp(ob[i]) ) {
				message_vision(ob[i]->name() + "怒喝一声：“" + me->name() + "你这"
					 + RANK_D->query_rude(me) + "，敢欺我同门！”\n", me);
				ob[i]->fight_ob(me);
				me->fight_ob(ob[i]);
			}
		}
	}

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : kill <人物>

这个指令让你主动开始攻击一个人物，并且试图杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: hit, fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
