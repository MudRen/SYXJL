// cimu.c 



#include <ansi.h>



inherit F_SSERVER;

int perform(object me, object target)

{

	string msg;

	int pp,damage,mm,tt;

	//pp=target->query_temp("pixie");

	if( !target ) target = offensive_target(me);

	 if( !present("xiuhua zhen",me))

                return notify_fail("������û���廨�룬����̱����۾���\n");

	if( !target

	||	!target->is_character()

	||	!me->is_fighting(target) )

		return notify_fail("��Ŀֻ�ܶ�ս���еĶ���ʹ�á�\n");

	

	if(me->query_skill("pixie-jian",1)<120)

		return notify_fail("���а������̫����������ʹ������Ŀ��һʽ��\n");

	if(me->query("neili")<200)

		return notify_fail("����������������ʹ������Ŀ��һʽ��\n");

	//if( target->is_busy() )

	

//		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");



	msg = GRN "$Nʹ����а����������Ŀ���������һ���廨�룬�������𣬴�$n��ͷ���ӹ���ͬʱ�����廨�����$n��˫Ŀ��\n";

	target->set_temp("pixie",(int)(target->query_temp("pixie")+10));

	pp=(int)target->query_temp("pixie");

	me->start_busy(random(3));

	mm=random((int)me->query_skill("dodge",1))+(int)me->query("dex");

	tt=random((int)target->query_skill("parry",1))+pp+(int)target->query("dex");

	if( target->is_busy() )

	me->set_temp("cimu",1);

	

	if(!target->is_busy()&&random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 

	{

		msg += "$p��ǰ����ǧ��֧��Ӱ��������ң���$P���˸����ֲ�����\n" NOR;

         

	target->start_busy(3);

		me->set_temp("cimu",1);

	}

	/*	if(random((int)me->query_skill("dodge",1))+(int)me->query("dex"))>random((int)target->query_skill("parry",1)+(int)target->query("int"))

		{

		msg += "$p��$P�̸����ţ��ҽ�һ��������һ�ᣬ�˺�������\n" NOR;	

		damage = 3*(int)me->query_skill("pixie-jian", 1);

                damage = damage/2 + random(damage);

                target->receive_damage("qi", damage);

                target->receive_wound("qi", damage);

                me->add("neili", -300);

		target->delete_busy();

		me->start_busy(random(5));

		//target->set_temp("pixie",0);

		target->kill_ob(me);

		}

	 */

	else 	

	msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;

	message_vision(msg, me, target);

	if((int)me->query_temp("cimu")==1&&mm>tt)

		{

		msg = RED"$p��$P�̸����ţ��ҽ�һ����˫����Ŀ������һ�ᣬ�˺�������\n" NOR;

		message_vision(msg, me, target);	

		damage = 2*(int)me->query_skill("pixie-jian", 1);

                damage = damage/2 + random(damage);

                target->receive_damage("qi", damage+50);

                target->receive_wound("qi", damage);

                me->add("neili", -150);

		target->delete_busy();

		me->start_busy(random(5));

	//	me->set_temp("cimu",0);

		target->set_temp("pixie",0);

		target->kill_ob(me);

		}

	me->set_temp("cimu",0);

	return 1;

}

