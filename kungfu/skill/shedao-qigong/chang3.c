

#include <ansi.h>



inherit F_SSERVER;



int perform(object me, object target)

{

        int neili,damage;


	if( !target ) target = offensive_target(me);



	if( !target

	||	!target->is_character()

	||	!me->is_fighting(target) )

		return notify_fail("���ɷ�ֻ����ս����ʹ�á�\n");



	if( (int)me->query_skill("shedao-qigong", 1) < 100 )

		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ����־���\n");



	if( environment(me)->query("no_fight") )

		return notify_fail("�����ﲻ�ܹ������ˡ�\n");



	if( (int)me->query("neili") < 500 )

		return notify_fail("���Ѿ����þ�ƣ����,���������ˡ�\n");





	neili = me->query("neili");



	me->add("neili", -(300+random(200)));

	me->receive_damage("qi", 10);



	me->start_busy(random(5));



	message_vision(

		HIY "$N�������һ��������Ȼ���쳤Х��������У�����������Ψ�Ҳ��ܣ�\n" NOR, me);



		if( neili/2 + random(neili/2) < (int)target->query("neili")/10) 

		return notify_fail("���˵���������߳�̫��,�˲��ˣ�\n");

		

		damage = (neili - (int)target->query("max_neili")) / 10;

		if( damage > 0 ) {

			target->receive_damage("jing", damage);

			target->receive_damage("qi", damage);

			target->receive_wound("qi", damage);

			target->receive_wound("qi", damage);

		message_vision(

		HIR "$Nֻ������һ���ʹ��������ð��������������������ǰ�趯��\n" NOR, target);

		}

		else

		{

		message_vision(

		HIR "$Nֻ������΢ʹ���ƺ�����һ�����ˡ�\n" NOR, target);

		target->receive_damage("jing", 10 );

		target->receive_damage("qi", 10 );

		target->receive_wound("qi", 10);

		}

		if( !target->is_killing(me) ) target->kill_ob(me);

		if( !me->is_killing(target) ) me->fight_ob(target);



	return 1;

}

