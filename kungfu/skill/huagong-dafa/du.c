// du.c  ������ ֮ �������־�
// by QingP

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, attackp, defendp;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("�㲻�����û���������󷨣��޷��ˡ������־���\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á������־���\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 45 )
		return notify_fail("��Ļ����󷨲�����죬����ʹ�á������־���\n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 70 )
		return notify_fail("��ı�ڤ������������������ʹ�á������־���\n");

	if( (int)me->query("neili",1) < 120 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	message_vision( HIR "$N�����۶����ƣ�˫�����ܶ�ʱ����һ���������޵Ķ���\n"
		 + HIY"ֻ������Ȼ�����������$nȫ��\n" NOR,
		me, target );

	attackp = me->query_skill("huagong-dafa", 1) + me->query_skill("beiming-zhenqi", 1) / 2 + me->query_skill("zhaixinggong",1) / 4;
	defendp = target->query_skill("force") + target->query_skill("dodge");

	if( attackp + random(attackp) > defendp || !living(target) )
	{
		message_vision(HIG "$p�����ӻ��˻Σ�ȴδ���ܣ���������˸����š�\n" NOR, me, target );
		tell_object( target, HIG "���ͷ��һ��ѣ�Σ���ʱ�лк�����������ʧ���ۿ�����Ϯ��ȴ�޷���ܡ�\n"
			 + HIR "��ļ���������һ��������ʱ�����쳣��\n" NOR);

		if( !target->is_killing(me) ) target->kill_ob(me);

		damage = ((int)me->query_skill("huagong-dafa", 1) + (int)me->query_skill("beiming-zhenqi", 1))/2;
		damage = damage/2 + random(damage);
		
		target->receive_damage("jing", damage/2);
		target->receive_wound("jing", damage/3);
		target->receive_damage("qi", damage/2);
		target->receive_wound("qi", random(damage/2));

		me->start_busy(2);
		me->add("neili", -100);
		target->start_busy(2 + random(1));

	}
	else
	{	
		message_vision(HIY "����$p������$P����ͼ��Ѹ�ٵرܿ��˶��ơ�\n" NOR, me, target);
		me->start_busy(random(2));
	}

	return 1;
}