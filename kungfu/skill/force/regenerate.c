// regenerate.c



//inherit SSERVER;



int exert(object me, object target)

{

	if (target != me) 

		return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");

	

	if ((int)me->query("neili") < 20)

		return notify_fail("�������������\n");

	if( (int)me->query("jing")>=(int)me->query("max_jing"))

		return notify_fail("�����ھ�����档\n");



	me->add("neili", -20);

	me->receive_heal("jing", (int)me->query_skill("force") / 3);

	

        message_vision("$N�������˼����������������ö��ˡ�\n", me);



        if( me->is_fighting() ) me->start_busy(1);

	

	return 1;

}



