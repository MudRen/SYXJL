// yizhi.c 一阳指 「一指定乾坤」
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
        if((int)me->query_str() < 28)
                return notify_fail("你臂力不够,不能使用这一绝技!\n");

        if((int)me->query_skill("kurong-changong",1) < 100)
                return notify_fail("你枯荣禅功的功力不够不能使用!\n");

        if((int)me->query_skill("finger") < 120)
                return notify_fail("你的指法修为不够,目前还不能使用「一指定乾坤」绝技!\n");

        if((int)me->query("neili") < 300)
                return notify_fail("你内力现在不够, 不能使用「一指定乾坤」! \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧!\n");

        msg = HIY "$N使出一阳指绝技「一指定乾坤」，罩住了$n的全身要穴, 使$n动弹不得。\n"NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
        {
                msg +=  HIG "结果$p被$P攻了个措手不及! \n" NOR;
                target->start_busy( (int)me->query_skill("yiyang-zhi",1) / 15 + 3);
                me->add("neili", -100);
        }
        else
        {
                msg += HIM "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}


