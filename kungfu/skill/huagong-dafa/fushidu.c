// fushidu.c ������ ֮ ��ʬ��
// by QingP

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, attackp, defendp;
	object obj;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("�㲻�����û���������󷨣��޷�ʩ����ʬ������\n");

	if( !target ) target = offensive_target(me);

	if( !target	|| !target->is_character() ||	!me->is_fighting(target) )
		return notify_fail("��ʬ��ֻ����ս����ʹ�á�\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 45 )
		return notify_fail("��Ļ����󷨲�����죬����ʩ��ʬ����\n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 110 )
		return notify_fail("��ı�ڤ������������������ʩ��ʬ����\n");

	if( (int)me->query("neili",1) < 170 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if ((int)me->query_skill("throwing", 1) < 70)
		return notify_fail("��Ļ�������������죬����ʩ��ʬ����\n");

	if ( !(objectp(obj=present("corpse", environment(me)))
	     || objectp(obj=present("corpse", me))
	     || objectp(obj=present("Skeleton", environment(me)))
	     || objectp(obj=present("Skeleton", me)) ) )
		return notify_fail("����Χû��ʬ��, ��ôʩ��ʬ��?\n");

	message_vision( CYN "$N˳��ץ��ʬ�壬ֻ��ʬ�嶸Ȼ�����������, ��$n��ֱ��ȥ��\n"NOR, me, target );

	attackp = me->query_skill("huagong-dafa",1) + me->query_skill("beiming-zhenqi",1) + me->query_skill("throwing",1) * 2;
	defendp = target->query_skill("force",1) + target->query_skill("dodge") * 2;

	if( attackp / 4 + random( attackp ) > defendp )
	{
		message_vision( CYN " ֻ�����������죬���Ÿ��˱����ŵ�һ�ɽ���������������Ż��\n"
		+ "���$p��$P���˸����ţ�\n" NOR, me, target );

		damage = me->query_skill("huagong-dafa",1) + (int)me->query_skill("beiming-zhenqi", 1)/2;
		damage = damage - random( target->query_skill("dodge")/2 );

		target->receive_damage("jing", damage/2);
		target->receive_wound("jing", random(damage/2));
		target->receive_damage("qi", 70 + damage );

		me->start_busy(2);
		target->start_busy(1 + random(3));

	}
	else {
		message_vision( HIY "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR, me, target );
		me->start_busy(1);
	}

	if( !target->is_killing(me) ) target->kill_ob(me);

	me->add("neili", -135);
	destruct(obj);

	return 1;
}