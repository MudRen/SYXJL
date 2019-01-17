// jing.c 静

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int i, l;
        i = me->query_skill("qiantian-yiyang", 1);   
        l = me->query_skill("buddhism", 1);  
    
        if( !target ) target = me;

        if (me->query("class") != "bonze" )
               return notify_fail("你非佛门弟子，这等大慈大悲感化世人之事，你是不了解的。\n");
        
        if(me->is_fighting())
              return notify_fail("你正在战斗中，如何可以静下心来？\n");
        if((int)me->query_skill("qiantian-yiyang",1) < 120 )
              return notify_fail("你的乾天一阳功不够娴熟，内力的冲撞使你静不下心来！\n");
        if( (int)me->query_skill("buddhism",1) < 110 )
              return notify_fail("你的佛学修为不够，无法静下心来！\n");
        
        if( (int)me->query("max_neili") < 1200  ) 
                return notify_fail("你的内力不够。\n");     
        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的真气不够。\n");

        if((int)target->query_condition("dali_kong") > 0 )
                return notify_fail("你已入佛家舍身忘我之境。\n");
       
        me->add("neili", -1000);

        message_vision(
        HIW "\n$N闭目盘膝坐下，缓缓磨去心中杂念，随即睁开眼来，但见$N目光甚是柔和，充满了悲悯之意。\n" NOR, me);

        me->apply_condition("dali_kong", (i + l)/15);  
       
        
        return 1;
}
> cat kong.c
// jing.c 静

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int i, l;
        i = me->query_skill("qiantian-yiyang", 1);   
        l = me->query_skill("buddhism", 1);  
    
        if( !target ) target = me;

        if (me->query("class") != "bonze" )
               return notify_fail("你非佛门弟子，这等大慈大悲感化世人之事，你是不了解的。\n");
        
        if(me->is_fighting())
              return notify_fail("你正在战斗中，如何可以静下心来？\n");
        if((int)me->query_skill("qiantian-yiyang",1) < 120 )
              return notify_fail("你的乾天一阳功不够娴熟，内力的冲撞使你静不下心来！\n");
        if( (int)me->query_skill("buddhism",1) < 110 )
              return notify_fail("你的佛学修为不够，无法静下心来！\n");
        
        if( (int)me->query("max_neili") < 1200  ) 
                return notify_fail("你的内力不够。\n");     
        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的真气不够。\n");

        if((int)target->query_condition("dali_kong") > 0 )
                return notify_fail("你已入佛家舍身忘我之境。\n");
       
        me->add("neili", -1000);

        message_vision(
        HIW "\n$N闭目盘膝坐下，缓缓磨去心中杂念，随即睁开眼来，但见$N目光甚是柔和，充满了悲悯之意。\n" NOR, me);

        me->apply_condition("dali_kong", (i + l)/15);  
       
        
        return 1;
}