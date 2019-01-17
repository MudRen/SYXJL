//amber 1999.10.18
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
        if (me->query_temp("jinshe/tuwu"))
                return notify_fail("你才用的金蛇吐雾，没法接着就出招。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("金蛇吐雾只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "jinshe zhui")
           return notify_fail("你没用金蛇锥，不能使用绝招！\n");
//        if( target->is_busy() )
//                return notify_fail(target->name() + "已经被毒雾迷住了，你还吐什么雾？？想毒自己啊！！\n");   
        if( (int)me->query_skill("jinshe-zhuifa", 1) < 150 )
                return notify_fail("你的金蛇锥法不够娴熟，不会使用金蛇吐雾。\n");
//        if( (int)me->query_skill("jinshe-jianfa",1) < 150)        
//                return notify_fail("你的金蛇剑法不够娴熟，不会使用金蛇吐雾。\n");
        if( (int)me->query_skill("dodge") <150)
                return notify_fail("你的轻功修为不够，使不出金蛇吐雾。\n");
        if( (int)me->query_skill("throwing") <150)
                return notify_fail("你的基本功夫都没练好怎么能发出金蛇吐雾？？？\n");
        if((int)me->query_dex() < 30)
                return notify_fail("你身法这么差发出去的暗器能打中人吗！！！ \n");
        if((int)me->query_skill("force") < 150)
                return notify_fail("以你现在的内功修为发出去的暗器不能伤人！！！ \n");        
        if( (int)me->query_str() < 30 )
                return notify_fail("你就这么点力气发出的暗器也想伤人！！！\n");                
        if( (int)me->query("jing") <50)
                return notify_fail("你精力不够了。\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("你内力不够了。\n");   
                   
        message_vision(HIG"只听一阵狂风扫叶般的声响中,$N手中的"HIY"金蛇锥"HIG"闪出夺目的光芒，闪耀得$n眼冒金
        花。\n" NOR,me,target);
        
        if( random( (int)me->query_skill("jinshe-zhuifa",1))
          > random(target->query_skill("dodge")*2/3 ) ) 
          {
        msg = WHT"！！！金蛇吐雾！！！"HIG"除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR,me, target;
        skill = me->query_skill("jinshe-zhuifa", 1);

        me->add("jing",-30);
        me->add("neili", -300);
        target->receive_damage("qi", (int)skill* 3);
        target->receive_damage("jing",(int)skill/ 3);
        target->receive_wound("jing",(int)skill/ 4);
        target->receive_wound("qi",(int)skill* 2);
        me->set_temp("jinshe/tuwu", 1);
        target->set_temp("block_msg/all",1);
        call_out("tuwu_end", (int) skill/20, me, target);
        me->start_busy(random(2));
        target->start_busy( (int)me->query_skill("jinshe-zhuifa",1) / 40 ) + random( (int)me->query_skill("jinshe-zhuifa",1) / 100 );


        } else {
                msg = HIW"可是$p看破了你的企图，急运内力双袖中喷出一股内家真气驱散了浓雾，躲了开去。\n" NOR;
                me->start_busy((2)+random(2));
                me->add("jing",-10);
                me->add("neili",-100);
        }
        message_vision(msg, me, target);
        return 1;
        }
void tuwu_end(object me, object target)
{
        target->enable_player();
        message_vision("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n" NOR, target);
        target->set_temp("block_msg/all", 0);
        write(HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
        me->delete_temp("jinshe/tuwu");

        return;
}

