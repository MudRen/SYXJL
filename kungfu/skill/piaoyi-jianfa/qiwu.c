// 起舞弄清影
// bye jfeng
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    string msg;
        if( !me->is_fighting() )
            return notify_fail("「起舞弄清影」只能在战斗中使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
        if((int)me->query_skill("murong-xinfa",1) < 100)
                return notify_fail("你的慕容心法火候还不到家, 不能使用这一绝技 !\n");
        if((int)me->query_skill("sword",1) < 100)
                return notify_fail("你的基本剑法火候还不到家, 不能使用这一绝技 !\n");
        if((int)me->query_skill("piaoyi-jianfa",1) < 100)
                return notify_fail("你的飘逸剑法火候还不到家, 不能使用这一绝技 !\n");
        if( (int)me->query("neili") < 700 )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query("max_neili") < 700 )
                return notify_fail("你的内力修为不够！\n");
    msg = 
HIC "\n$N长叹一声，手弹长剑，身形飘忽不定，使的正是飘逸剑法的绝技「起舞弄清影」！\n" NOR;
        message_vision(msg, me);
        me->clean_up_enemy();
        ob = me->select_opponent();
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili",-random(150)-50);
    return 1;
}
