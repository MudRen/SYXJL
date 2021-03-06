// tan.c  霹雳弹 「弹字诀」
//create bye cuer
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object obj; 
        int kill=0;
        
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("暗器射敌只能对同地方的对手使用。\n");
        if( !present("pili dan",me))
                return notify_fail("你身上没有带霹雳弹，还想暗算人？\n");
        if( (int)me->query_skill("pili-dan", 1) < 80 )
                return notify_fail("你的霹雳弹不够娴熟，不会使用「弹字诀」。\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 30 )
                return notify_fail("你的临济十二庄不够高，不能用内力发射暗器。\n");
        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("你现在内力太弱，不能发射暗器。\n");
        msg = CYN "突然从暗处射出一粒霹雳弹，击向$n。\n"NOR;
        if (random(me->query_skill("pili-dan")) > target->query_skill("dodge")/3 )
        {
                me->start_busy(1);
                target->start_busy(1+random(1));
                damage = 2*(int)me->query_skill("pili-dan", 1);
                damage = damage/2 + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -100);
                 msg += HIR"结果$n被霹雳弹射中，惨叫一声，身子一歪，退后丈许！！\n"NOR;
        }
        else
        {
                me->start_busy(1);     
                target->start_busy(random(1));
                me->add("neili",-100);
                msg += CYN"可是$p看到了霹雳弹，躲开了。\n"NOR;
        }                                    
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        { 
                msg += CYN"$p没有发现霹雳弹的来源！\n"NOR;
        }                                                 
        else
        { 
                msg += HIR"$p发现了射霹雳弹的人了！\n"NOR;
                kill = 1;                
        }
        message_vision(msg, me, target);
        obj = present("pili dan",me);
        destruct(obj);              
        if(kill==1)
           target->kill_ob(me);
        return 1;
}
