// shenjian.c 桃花影里飞神剑

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage, rand;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("桃花影里飞神剑只能对战斗中的对手使用。\n");

        if (!(me->query("thd/perform") & 2))
                return notify_fail("你虽然听说过“桃花影里飞神剑”这一招，可是却未获传授。\n");

        if( (int)me->query_skill("luoying-zhang", 1) < 80 )
                return notify_fail("你的落英神剑掌不够娴熟，无法使用桃花影里飞神剑。\n");

        if ( (int)me->query("neili") < 120)
                return notify_fail("你的内力不够，无法使用桃花影里飞神剑。\n");

        msg = CYN "$N双掌竖起，掌缘便似剑锋，竟然发出丝丝的剑气，从左右两边分斫$n。\n";

        rand = random(me->query("combat_exp"));
        if( rand > (int)target->query("combat_exp")/2 ) {
                msg += "$n躲闪不及，被两掌同时砍中！\n";
                damage = (int)me->query_skill("luoying-zhang", 1);
                damage += random(damage / 2);
                if (damage > target->query("neili") / 8)
                        damage -= target->query("neili") / 15;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                if( damage < 40 ) msg += HIY"$n的脸色大变，被斫处疼痛难忍。\n"NOR;
                else if( damage < 80 ) msg += HIR"$n的内息竟然一滞，全身似乎都要瘫了！\n"NOR;
                else msg += RED"$n手捂胸口，“哇”的一声吐出了一口鲜血。\n"NOR;
                message_vision(msg, me, target);
        } 
        else if( rand > (int)target->query("combat_exp")/3 ) {
                msg += "$n躲过了一掌，还是无法躲开另一掌！\n";
                damage = (int)me->query_skill("luoying-zhang", 1);
                damage = damage / 2 + random(damage / 2);
                if (damage > target->query("neili") / 10)
                        damage -= target->query("neili") / 15;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                if( damage < 40 ) msg += HIY"$n的脸色大变，被斫处疼痛难忍。\n"NOR;
                else if( damage < 80 ) msg += HIR"$n的内息竟然一滞，全身似乎都要瘫了！\n"NOR;
                else msg += RED"$n手捂胸口，“哇”的一声吐出了一口鲜血。\n"NOR;
                message_vision(msg, me, target);
        } 
        else {
                msg += "$n大吃一惊，退步抽身，万分惊险中堪堪躲过了这招，早已吓出了一身冷汗！\n" NOR;
                message_vision(msg, me, target);
        }
        me->add("neili", -80);
        me->start_busy(1);

        return 1;
}
