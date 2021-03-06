// lifeheal.c

#include <ansi.h>
#include <cond.h>
#include <spec.h>

int exert(object me, object target)
{
       if(!target)
        return notify_fail(HIC"你要替谁疗伤。\n"NOR);
      if(target==me) 
      return notify_fail(HIC"该功能只能施于别人。\n"NOR);
      if(!together(me,target))
      return notify_fail(HIC"这种情况下你无法为"+target->name()+"发功。\n"NOR);
        if(me->is_busy())
         return notify_fail("你太忙了。\n");
        if( !target )
                return notify_fail("你要用真气为谁疗伤？\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功疗伤！\n");
        if ((int)me->query_skill("xiake-shengong", 1) < 50)
               {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("你的侠客神功火候不够,小心走火入魔。\n");
                }


        if( (int)me->query("max_neili") < 300 )
              {
            if(test_zouhuorumo(me)) return notify_fail("");    
        return notify_fail("你的内力修为不够，强自运气会导致走火入魔。\n");
                 }

        if( (int)me->query("neili") < 100 )
             {
            if(test_zouhuorumo(me)) return notify_fail("");    
                return notify_fail("你的真气不够，强自运气会导致走火入魔。\n");
              }
        if((me->query("eff_jing")*100/me->query("max_jing"))<70)
            {
           if(test_zouhuorumo(me)) return notify_fail("");
           return notify_fail("你的精力不够，可能会走火入魔。\n");
             }

        if((me->query("eff_qi")*100/me->query("max_qi"))<60)
          {
          return notify_fail("你先疗疗自己的伤吧。\n");
            }
        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
              {
             if(test_zouhuorumo(target)) return notify_fail("");    
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");
               }

        message_vision(
                HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
                "过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
                me, target );

        target->receive_curing("qi", 20 + (int)me->query_skill("force")/3 );
        target->receive_curing("jing",10+(int)me->query_skill("force")/3);   
        target->add("qi", 30 + (int)me->query_skill("force")/3 );
        if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
        
        me->receive_damage("qi",20);
        me->add("neili", -80);
        me->set("jiali", 0);
        me->start_busy(1);
        target->start_busy(1);   
        return 1;
}
