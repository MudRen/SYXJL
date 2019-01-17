// chillgaze.c

#include <ansi.h>
//inherit F_CLEAN_UP;
//inherit SSERVER;
inherit F_SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage;

	if( !me->is_fighting() )
		return notify_fail("���Ի�󷨣�ֻ����ս����ʹ�á�\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("�������������\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("��Ҫ��˭ʩչ���Ի�󷨣ݣ�\n");
	}
	if(target->query("name")=="Ҷ��")return notify_fail("�㲻�ʺ��������书.");
	skill = me->query_skill("force");

	me->add("neili", -50);
	me->receive_damage("qi", 20);

	message_vision(
		HIB "\n$N����������죬˫�۱���쳣���ʣ�\n" NOR, me, target);
	
	if( random(target->query("combat_exp")) > (int)me->query("combat_exp") / 2 ) {
		message_vision("$N�ܿ��ת��ͷȥ���ܿ���$n��Ŀ�⡣\n", target, me);
		// me->start_busy(3);
		return 1;
	}
	skill = me->query_skill("force");
	damage = skill * 2 - target->query("force") / 15;
	if( damage < 1 ) {
		message_vision("����$N��$n��ע�������޶�....��\n", target, me);
	//	me->start_busy(3);
		return 1;
	}

	target->receive_damage("jing", damage);
	if( random(skill) > (int)target->query("cps") * 2 )
		target->start_busy(5);
	message_vision("$N��$n�Ĺ����������󣬲��Խ�������������\n", target, me);
	
	me->start_busy(1);
	return 1;
}

