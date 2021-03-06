// /kungfu/skill/hua.c 玉萧剑法 势合形离
// adx 22:08 99-2-11
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「势合形离」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("yuxiao-jianfa", 1) < 60 )
                return notify_fail("你的玉萧剑法极不够娴熟，不会使用「漫天花雨」。\n");

        if( (int)me->query_skill("bibo-shengong", 1) < 160 )
                return notify_fail("你的碧波神功不够娴熟，不会使用「漫天花雨」。\n");

        msg = CYN "$N手腕一抖，一式「势合形离」，泛出数朵剑花连续递出。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
        {
                msg += CYN " 结果$p被$P攻了个措手不及！\n" NOR;
                attack_time = random((int)me->query_skill("yuxiao-jianfa", 1) / 30);
                if(attack_time < 1)
                        attack_time = 1;

                for(i = 0; i < attack_time; i++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

                me->start_busy(random(2));
                me->add("neili", -100);
        }
        else
        {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(random(3));
        }
        message_vision(msg, me, target);

        return 1;
}

