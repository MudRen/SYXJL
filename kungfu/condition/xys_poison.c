// xiaoyao_poison.c

// by QingP



#include <ansi.h>

#include <condition.h>



inherit F_CLEAN_UP;



int update_condition(object me, int duration)

{

	if ( duration == 2 ){

		tell_object(me, HIB "周围的人都用奇怪的眼神打量着你，但并没有发生什么事。\n" NOR );

		message("vision", me->name() + HIR "忽然间微微一笑，神情颇为诡秘，似乎有点不怀好意。\n" NOR,

		environment(me), me);

	}

	else if (duration == 1 ){

			tell_object(me, HIB "周围的人都用奇怪的眼神打量着你，但并没有发生什么事。\n" NOR );

			message("vision", me->name() + HIR "突然间微微一笑，神色古怪，不知又在打什么坏主意。\n" NOR,

			environment(me), me);

	}

	else if (duration == 0 ){

			tell_object(me, HIB "周围的人都用奇怪的眼神打量着你，但并没有发生什么事。\n" NOR );

			message("vision", me->name() + HIR "脸上突然现出诡秘之极的笑容。\n" NOR,

			environment(me), me);

			me->die();

			return 0;

	}

	

	me->apply_condition("xys_poison", duration - 1);

	

	return 1;

}