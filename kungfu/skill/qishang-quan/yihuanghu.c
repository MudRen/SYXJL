
// yihuanghu.c 意恍惚诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("qishang-quan",1) + me->query_skill("jiuyang-force",1);

        if( !me->is_fighting() )
                return notify_fail("「意恍惚诀」只能在战斗中使用。\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的内力还不够高！\n");

        if( (int)me->query_skill("cuff") < 150 )
                return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！\n");

        if( (int)me->query_skill("qishang-quan", 1) < 150)
                return notify_fail("你七伤拳的修为不够，不能够体会意恍惚诀! \n");

          if( (int)me->query_skill("shenghuo-shengong", 1) < 150)
                  return notify_fail(HIM "你的圣火神功修为不足，不能随便使用意恍惚诀! \n" NOR);

        if( me->query_skill_mapped("cuff") != "qishang-quan")
                return notify_fail("你没有激发七伤拳，无法运用意恍惚诀！\n");

        msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "意恍惚诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 4;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-300);

                msg = HIC "结果$N双拳击中时，却是若有若无。\n$n正在奇怪间，已被$N的真气制住，神情恍恍忽忽的！\n"NOR;
                target->start_busy((int)skill/20);
                me->start_busy(2);
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
