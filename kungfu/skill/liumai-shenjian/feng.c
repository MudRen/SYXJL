// feng.c 六脉神剑 - 封
// Written by Doing Lu 1999/1/4

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「封」字决指法只能对战斗中的对手使用。\n");

        if (objectp(weapon = me->query_temp("weapon")))
                        return notify_fail("你不能使用武器！\n");

        if( (int)me->query_skill("liumai-shenjian", 1) < 90 )
                return notify_fail("你的六脉神剑太生疏，不会使用「封」字决。\n");

        if ( me->query("neili") < 300)
                return notify_fail("你的内力不够，现在无法使用「封」字决。\n");
        me->add("neili", -30);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
                
        msg = HIY "$N长出一口气，使出六脉神剑「封」式，指指点点，剑气如潮而至。\n";

          me->start_busy(3);
        me->add("neili", -30);
          if( random( me->query("neili") + me->query("dodge") * 10 ) > random((int) target->query("dodge") * 10) ) {
                msg += HIR " $p强做精神，左遮右挡，无法还手！\n" NOR;
                target->start_busy( (int)me->query_skill("liumai-shenjian", 1) / 20 );
        } else {
                msg += "可是$p身形一错，已飘然脱离$P的攻击。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
