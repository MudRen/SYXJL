// xiaoyao_poison.c

// by QingP



#include <ansi.h>

#include <condition.h>



inherit F_CLEAN_UP;



int update_condition(object me, int duration)

{

	if ( duration == 2 ){

		tell_object(me, HIB "��Χ���˶�����ֵ�����������㣬����û�з���ʲô�¡�\n" NOR );

		message("vision", me->name() + HIR "��Ȼ��΢΢һЦ��������Ϊ���أ��ƺ��е㲻�����⡣\n" NOR,

		environment(me), me);

	}

	else if (duration == 1 ){

			tell_object(me, HIB "��Χ���˶�����ֵ�����������㣬����û�з���ʲô�¡�\n" NOR );

			message("vision", me->name() + HIR "ͻȻ��΢΢һЦ����ɫ�Ź֣���֪���ڴ�ʲô�����⡣\n" NOR,

			environment(me), me);

	}

	else if (duration == 0 ){

			tell_object(me, HIB "��Χ���˶�����ֵ�����������㣬����û�з���ʲô�¡�\n" NOR );

			message("vision", me->name() + HIR "����ͻȻ�ֳ�����֮����Ц�ݡ�\n" NOR,

			environment(me), me);

			me->die();

			return 0;

	}

	

	me->apply_condition("xys_poison", duration - 1);

	

	return 1;

}