// heal.c by rhxlwd 99.02

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
               return notify_fail("战斗中疗精？找死吗？\n");

          if ((int)me->query_skill("beiming-shengong", 1) < 50)
                return notify_fail("你的北冥神功修为还不够。\n");
          if( (int)me->query("jingli") < 50 ) // - (int)me->query("max_jingli") < 50 )
                    return notify_fail("你的精力不够。\n");

          if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

          write( HIG "你心无杂念，坐下来开始养精序锐。\n" NOR);
        message("vision",
                  HIG + me->name() + "长吐一口气，精神看起来好多了。\n" NOR,
                environment(me), me);

          me->receive_curing("jing", 10 + (int)me->query_skill("force")/5 );
          me->add("jingli", -50);
        me->set("jiali", 0);
      me->start_busy(4);

        return 1;
}

