//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) )
	{
		message("vision", me->name() + "���������󲡵ò��ᡣ\n", environment(me), me);
	}
	else 
	{
		tell_object(me, HIG "ͻȻ������֮��һ���ڣ���е��������¶����ܡ�\n" NOR );
		message("vision", me->name() + "���������������ˡ�\n",environment(me), me);
	}
	me->receive_wound("qi",5 + random(5));
	me->receive_wound("jing", 5);
	me->apply_condition("ill_zhongshu", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

