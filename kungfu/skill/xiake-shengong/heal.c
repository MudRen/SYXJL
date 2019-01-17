// heal.c

#include <ansi.h>
#include <cond.h>

int exert(object me, object target)
{
        if(me->is_busy())
         return notify_fail("你正忙。\n");
        if( me->is_fighting() )
               {
               if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("战斗中运功疗伤？找死吗？\n");
                }

        if ((int)me->query_skill("xiake-shengong", 1) < 30)
               {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("你的侠客神功火候不够,小心走火入魔。\n");
                }
        if( (int)me->query("max_neili") < 300 )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("你的内力修为不够小心走火入魔。\n");
               }
        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
          {
            if(test_zouhuorumo(me)) return notify_fail("");     
            return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
          }
write( HIW "你盘膝坐了下来，慢慢引导真气行走全身冲开被闭塞的经脉。\n" NOR);
        message("vision",
HIW + me->name() + "盘膝坐下来运功疗伤，脸上一阵红一阵白，过一会儿吐出几口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);
        me->receive_curing("qi", 30 + (int)me->query_skill("force")/5 );
        me->receive_curing("jing",10+(int)me->query_skill("force")/5);
        me->add("neili", -50);
        me->start_busy(1);
        me->receive_damage("qi",10);
        me->set("jiali", 0);

        return 1;
}
