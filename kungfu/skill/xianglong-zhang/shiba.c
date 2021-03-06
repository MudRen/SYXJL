// MOP@LDJ
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        object weapon,ob;
        extra = me->query_skill("xianglong-zhang",1);
        
        if( (int)me->query("neili") < 3000 )
                return notify_fail("你的真气不够！\n");

          if ((string)me->query("family/family_name") != "丐帮")
                return notify_fail("你不是丐帮中人怎么学会的降龙十八掌？！\n");

        if( (int)me->query_skill("strike") < 200 ||
            me->query_skill_mapped("strike") != "xianglong-zhang")
                return notify_fail("你的「降龙十八掌」还不到家，无法使用「大绝招」！\n");

        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "xiaoyaoyou")
                        return notify_fail("「大绝招」需要逍遥游的配合！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「大绝招」只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");

        me->clean_up_enemy();
        ob = me->select_opponent();
        if( !target->is_killing(me) ) target->kill_ob(me);
        msg = HIW  "$N双手有规律的划动，将降龙十八掌的招式划动的极快！\n\n"HIY"第一掌：亢龙有悔！\n\n$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第二掌：飞龙在天！\n\n"HIY"$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第三掌：见龙在田！\n\n"HIY"$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第四掌：鸿渐于陆！\n\n"HIY"$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第五掌：潜龙勿用！\n\n"HIY"$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第六掌：利涉大川！\n\n"HIY"$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第七掌：突如其来！\n\n"HIY"$N使出「突如其来」，右掌从不可能的角度向$n的$l推出" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第八掌：震惊百里！\n\n"HIY"$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第九掌：或跃在渊！\n\n"HIY"$N使出「或跃在渊」，向$n的$l连拍数掌" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十掌：双龙取水！\n\n"HIY"$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十一掌：鱼跃于渊！\n\n"HIY"$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十二掌：时乘六龙！\n\n"HIY"$N双掌立起，使出「时乘六龙」向$n连砍六下" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十三掌：密云不雨！\n\n"HIY"$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十四掌：损则有孚！\n\n"HIY"$N使出「损则有孚」，双掌软绵绵地拍向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十五掌：龙战于野！\n\n"HIY"$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十六掌：履霜冰至！\n\n"HIY"$N门户大开，一招「履霜冰至」向$n的$l劈去" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第十七掌：羝羊触蕃！\n\n"HIY"$N使出「羝羊触蕃」，双掌由下往上击向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "最后一掌：神龙摆尾！\n\n"HIY"$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -1500);
        me->start_busy(3);
        return 1;
}

