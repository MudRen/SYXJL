//By Hate@FCⅡ.

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(HIC"你要对谁施展绝招"HIY"「剑转七星」"HIC"？\n"NOR);

        if(!me->is_fighting())
                return notify_fail(HIY"「剑转七星」"HIC"只能在战斗中使用！\n"NOR);

        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力修为太差！\n");

   if((int)me->query("neili") < 1000 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("murong-jianfa", 1) < 200)
                return notify_fail("你的慕容剑法不够娴熟，无法使用剑转七星！\n"); 

        if( (int)me->query_skill("sword", 1) < 180 )
                return notify_fail("你的基本剑法不够娴熟，不能使用剑转七星。\n");

message_vision(HIR"\n$N忽然剑锋一转，将内力传至剑锋，只见七朵剑花绽开，分别袭向$n的七大要穴！\n"NOR,me,target);
message_vision(HIW"星转一斗："WHT"〖"HIY"天枢星"WHT"〗\n\n"HIG"只见$N手中之剑势一抖，笔直刺入$n的身体，$n只觉身上一痛，随即"HIC"『天门穴』"HIG"传来无法形容的剧烈疼痛！\n"NOR,me,target);        
          COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HIM"星斗又见："WHT"〖"HIY"天眩星"WHT"〗\n\n"HIG"只见$N剑势再抖，笔直刺入$n的肩头，$n只觉身上一痛，随即"HIC"『肩井穴』"HIG"传来一阵剧烈刺痛！\n"NOR,me,target);        
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(MAG"转星见斗："WHT"〖"HIY"天机星"WHT"〗\n\n"HIG"只见$N剑随势上，三剑又出，竟然绝不可能的刺入$n的足底！$n只觉轻微一痛，随即"HIC"『涌泉穴』"HIG"传来一阵剧烈疼痛！\n"NOR,me,target);        
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));message_vision(YEL"星转四斗："WHT"〖"HIY"天权星"WHT"〗\n\n"HIG"只见$N剑抖四星，笔直刺入$n的身体，$n只觉身上被一阵乱刺，随即感到"HIC"『任脉四穴』"HIG"传来一阵剧烈疼痛！\n"NOR,me,target);   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIB"五星在中："WHT"〖"HIY"玉衡星"WHT"〗\n\n"HIG"只见$N剑走偏锋，笔直刺入$n的腰侧，$n只觉腰上一痒，随即"HIC"『齐门穴』"HIG"竟然喷出血花！\n"NOR,me,target);           COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(RED"星聚遇斗："WHT"〖"HIY"开阳星"WHT"〗\n\n"HIG"只见$N抖剑而上，由上而下刺入$n的头顶，$n突然觉得全身真力不续，随即重穴"HIC"『百汇穴』"HIG"竟然疼痛无比！"NOR,me,target);  COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIR"斗转星移："WHT"〖"HIY"谣光星"WHT"〗\n\n"HIG"只见$N剑花连抖，如众星捧剑，任$n奋力闪躲，亦将$n的第一重穴"HIC"『太阳穴』"HIG"刺了两道血迹！\n"NOR,me,target);                       
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(WHT"\n$N祭完七星，收剑挺立场中，一代王者风范凛然而出！仿佛毫不在意$n的存在。\n"NOR,me,target);        
        
//        target->receive_damage("jing", 200)
        target->receive_damage("qi", 200+(int)me->query("max_neili")/2);
        me->receive_damage("jing", 50);
        me->add("neili", -500);

        me->start_busy(5);
        return 1;
}
