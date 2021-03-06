// xinjing.c 心静

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

int exert(object me, object target)
{
        int i, l, skill;
        i = me->query_skill("qiantian-yiyang", 1);   
        l = me->query_skill("buddhism", 1);  
        skill = (i + l)*2;

        if( !target ) target = me;
        
         if(me->is_fighting())
              return notify_fail("你正在战斗中，如何可以静下心来？\n");
        if(!me->query_skill("qiantian-yiyang",1))
          if((int)me->query_skill("qiantian-yiyang",1) < 60 )
              return notify_fail("你的内功还不够扎实，内力的冲撞使你静不下心来！\n");
        if( (int)me->query_skill("buddhism",1) < 100 )
              return notify_fail("你的佛学修为不够，无法静下心来潜修！\n");
             
        if( (int)me->query("max_neili") < 1100  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的真气不够。\n");

        if(me->query_temp("dali_jing"))
                return notify_fail("你正在静心潜修。\n");
       
        me->add("neili", -1000);

        message_vision(
        GRN "\n$N闭目盘膝坐下，只觉心中清静平和，渐渐进入忘我之境。\n" NOR, me);

        me->start_busy(3);
        me->add_temp("apply/intelligence", (int)me->query("int"));
        me->set_temp("dali_jing",1);  
       
        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill);
        return 1;
}

void remove_effect(object me)
{
        me->add_temp("apply/intelligence", -(int)me->query("int"));
        me->delete_temp("dali_jing");
        tell_object(me, HIY"你心中杂念又生，无法继续潜修了。\n"NOR);
}