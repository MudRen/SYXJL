// tie@fengyun



#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)

{

	string msg;

	int extra;

	object weapon;

	if( !target ) target = offensive_target(me);



	if( !target

	||	!target->is_character()

	||	!me->is_fighting(target) )

		return notify_fail("�ۻ�Ȼһ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");

	extra = me->query_skill("doomsword",1) / 5;

	me->add_temp("apply/attack", extra);	

	me->add_temp("apply/damage", extra);

	msg = HIR  "$N������ǰ�����е�"+ weapon->name() +"һʽ�ۻ�Ȼһ���ݣ���â�������޵���$n��ȥ��" NOR;

        me->add_temp("apply/attack", -extra);

	

        me->add_temp("apply/damage", -extra);

	me->start_busy(2);

	return 1;

}
