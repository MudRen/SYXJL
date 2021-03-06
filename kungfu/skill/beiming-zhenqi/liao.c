// liao.c 北冥真气 之 疗伤
// by QingP

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if ((int)me->query_skill("beiming-zhenqi", 1) < 20)
		return notify_fail("你的北冥真气修为还不够。\n");
	if( (int)me->query("neili") < 40 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") * 3 / 10 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") )
                message_vision( HIW "$N左手如弹琵琶，一阵轮指虚点，顷刻间封了伤口上下左右各处穴道。\n" NOR, me);
	message_vision( HIY "$N盘膝坐下，开始运功疗伤。\n" NOR, me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	me->add("qi", 15 + (int)me->query_skill("force")/2 );
	if( (int)me->query("qi") > (int)me->query("eff_qi") ) me->set("qi", (int)me->query("eff_qi"));

	me->add("neili", -30);
	me->set("jiali", 0);
	me->start_busy(3);

	return 1;
}
