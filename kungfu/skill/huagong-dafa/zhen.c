// zhen.c ������ ֮ �����־�
// by QingP from // zhen.c ̫��ȭ�����־�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, attackp, defendp;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("�㲻�����û���������󷨣��޷��ˡ����־���\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á����־���\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 70 )
		return notify_fail("��Ļ����󷨲�����죬����ʹ�á����־����\n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 100 )
		return notify_fail("��ı�ڤ������������������ʹ�á����־���\n");

	if( (int)me->query("neili",1) < 200 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	message_vision( HIC "$NĬ���񹦣��۶����ƣ�ʹ�������󷨡����־�����ͼ��������������$n������\n"NOR, me, target );

	attackp = me->query_skill("huagong-dafa", 1) + me->query_skill("beiming-zhenqi",1);
	defendp = target->query_skill("force");

	if ( attackp / 2 + random( attackp ) / 2 > defendp || !living(target) )
	{
		damage = (int)me->query_skill("huagong-dafa", 1) + (int)me->query_skill("beiming-zhenqi", 1);
		damage = damage + random(damage/2);
		
		target->receive_damage("jing", damage);
		target->receive_wound("jing", damage/2);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);

		me->start_busy(3);
		me->add("neili", -damage/3);
		target->start_busy(2 + random(3));
		
		if( damage < 20 )
			message_vision( HIY "���$n�ܵ�$N�����������ƺ�һ����\n"NOR, me, target);
		else if( damage < 40 )
			message_vision( HIY "���$n��$N���������𣬡��١���һ������������\n"NOR, me, target);
		else if( damage < 80 )
			message_vision( RED "���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR, me, target);
		else
			message_vision( HIR "���$n��$N������һ����ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR, me, target);

		tell_object( target, HIG "��������ʹ��ʣ�������ɢ�����ζ�ʱ����ɵü����˳�ȥ��\n"NOR );

		if( !target->is_killing(me) ) target->kill_ob(me);

	}
	else 
	{
		message_vision( CYN "����$p������$P����ͼ����û���ϵ���\n"NOR, me ,target);
		me->start_busy(2);
	}

	return 1;
}