// hua.c  ������ ֮ �������־�
// by QingP

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int attackp, defendp;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("�㲻�����û���������󷨣��޷��ˡ������־���\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ����˭��������\n");

	if( me->query_temp("hua") )
		return notify_fail("��ո��˹��������־�, ���ʻ�δ���!\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�û����󷨻���������\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 100 )
		return notify_fail("��Ļ����󷨲�����죬���ܻ����Է����������\n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 130 )
		return notify_fail("��ı�ڤ������������������ʩ�����󷨡�\n");

	if( (int)me->query("neili",1) < 270 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() + "���Ѿ�û���κ������ˣ�\n");

	message_vision( HIR "$NͻȻ�����һЦ������ٿȻ�ջأ�������Ѹ�ײ����ڶ�֮�ƺ��ض�׼$n�����ĳ���\n" NOR,
		me, target );

	attackp = me->query_skill("huagong-dafa", 1) + me->query_skill("beiming-zhenqi", 1) + me->query_skill("zhaixinggong", 1) / 2;
	defendp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("hua", 1);

	if( attackp / 2 + random(attackp) > defendp || !living(target) )
	{
		message_vision(HIY "$pһʱ�������ܣ�ֻ��ͦ����֡�\n" NOR, me, target );
		tell_object(me, HIG "���" + target->name() + "������ӭ�����д�ϲ���������𡰻����־������ж������ھ�ֱ�͹�ȥ...\n" NOR);
		message_vision(HIY "$p���һ�������ã���\n" NOR, me, target );
		tell_object(
			target, HIB "����������΢΢һ��������ԴԴ�����������ɢ����Ҳ���۲�������\n" + 
			"��ʱ����һ����ֻ��ȫ�����������û�����������п��������Ժ����ľ��ǰ���\n" 
			NOR);

		if( !target->is_killing(me) ) target->kill_ob(me);

		target->add("neili", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("jiali"))*2 );
		target->add("max_neili", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("jiali"))*2 );
		target->set_skill("force", target->query_skill("force", 1) - ((int)me->query_skill("huagong-dafa", 1) + target->query("jiali"))/10 );
		if( target->query("neili") <1 ) target->set("neili", 0);
		if( target->query("max_neili") <1 ) target->set("max_neili", 0);
		if( target->query_skill("force", 1) <1 ) target->set_skill("force", 0);

		if( target->query("combat_exp") >= me->query("combat_exp") )
		{
			if( (int)me->query("potential") - (int)me->query("learned_points") < 110 )
			me->add("potential", 7);
			me->add("combat_exp", 20);
		}

		me->start_busy(7);
		target->start_busy(2 + random(7));
		me->add("neili", -200);

		call_out("del_hua", 10, me);
	}
	else
	{	
		message_vision(HIY "����$p������$P����ͼ��Ѹ�ٵرܿ�����һ�ơ�\n" NOR, me, target);
		me->start_busy(4);
		call_out("del_hua", 17, me);
	}

	return 1;
}

void del_hua(object me)
{
	if ( me->query_temp("hua"))
	me->delete_temp("hua");
}