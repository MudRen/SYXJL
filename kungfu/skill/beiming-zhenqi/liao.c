// liao.c ��ڤ���� ֮ ����
// by QingP

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if ((int)me->query_skill("beiming-zhenqi", 1) < 20)
		return notify_fail("��ı�ڤ������Ϊ��������\n");
	if( (int)me->query("neili") < 40 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") * 3 / 10 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") )
                message_vision( HIW "$N�����絯���ã�һ����ָ��㣬��̼�����˿��������Ҹ���Ѩ����\n" NOR, me);
	message_vision( HIY "$N��ϥ���£���ʼ�˹����ˡ�\n" NOR, me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	me->add("qi", 15 + (int)me->query_skill("force")/2 );
	if( (int)me->query("qi") > (int)me->query("eff_qi") ) me->set("qi", (int)me->query("eff_qi"));

	me->add("neili", -30);
	me->set("jiali", 0);
	me->start_busy(3);

	return 1;
}
