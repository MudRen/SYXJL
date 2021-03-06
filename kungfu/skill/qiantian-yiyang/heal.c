// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if ((int)me->query_skill("qiantian-yiyang", 1) < 20)
                return notify_fail("你的乾天一阳功修为还不够。\n");
        if( (int)me->query("neili") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
                return notify_fail("你并没有受伤！\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIW "你全身放松，盘膝坐下，缓缓运起乾天一阳功来疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + "盘膝坐下，双掌掌心相对，缓缓运起乾天一阳功来。\n" + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);

        me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
        me->add("neili", -50);
        me->set("jiali", 0);

        return 1;
}
