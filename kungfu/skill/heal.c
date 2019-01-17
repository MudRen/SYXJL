// heal.c
// csy 1999/02/12

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("你的玉女心经修为还不够。\n");
        if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIB "你轻轻的吸一口气，闭上眼睛，运起玉女心经，内息在脉络中开始运转。\n" NOR);
        message("vision",
                HIB + me->name() + "气沉丹田，轻轻的吐出了一口气，神态恢复自然。\n" NOR,
                environment(me), me);

        me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
        me->add("neili", -50);
        me->set("jiali", 0);
      me->start_busy(4);

        return 1;
}

