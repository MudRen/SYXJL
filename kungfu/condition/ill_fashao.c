//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) )
	{
		message("vision", me->name() + "看起来好象病得不轻。\n", environment(me), me);
	}
	else 
	{
		tell_object(me, HIG "你感到浑身乏力，似乎还没退烧。\n" NOR );
		message("vision", me->name() + "看起来是象在发烧。\n",environment(me), me);
	}
	me->receive_wound("qi",5 + random(5));
	me->receive_wound("jing", 5);
	me->apply_condition("ill_fashao", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

