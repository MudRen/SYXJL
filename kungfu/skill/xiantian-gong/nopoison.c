#include <ansi.h>

int exert(object me, object target)
{
     if (target==me)
        {
        if( me->is_fighting())
                return notify_fail("战斗中无法运功解毒！\n");
        
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的内力不够。\n");

        if((int)me->query_skill("xiantian-gong", 1) <80)
                return notify_fail("你的先天功级别还不够！\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return
        notify_fail("你已经受伤过重，只怕一运内力便有生命危险！\n");
        write( CYN "你盘腿坐下，运起先天功开始解毒。\n" NOR);
        message("vision",
                CYN + me->name() +
     "盘腿坐下，运起先天功逼出体内的毒素。不久，吐出一口黑血，脸色好多了。\n"
        NOR,
                environment(me), me);
        
        me->add("neili", -300);
        me->add("max_neili", -5); 
        me->clear_condition();
        return 1;
        }
      
      else{
       if( !target )
                return notify_fail("你要为谁解毒？\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功解毒！\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的内力不够。\n");

       if((int)me->query_skill("xiantian-gong", 1) <100)
                return notify_fail("你的先天功级别还不够！\n");

       if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
       return notify_fail("你已经受伤过重，只怕一运内力便有生命危险！\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
        return notify_fail( target->name() + "已经受伤过重，经受不起你的内力冲击！\n");

        message_vision(
                CYN "$N盘腿坐下，运起先天功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
                "过了不久，$N额头上冒出豆大的汗珠。$n吐出一口黑血，脸色看起来红润多了。\n\n" NOR,
                me, target );

        target->clear_condition();
       me->add("neili", -300);
       me->add("max_neili", -10); 
       return 1;
      
       }

     return 1;
}
