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
                return notify_fail("�������������\n");

          if ((string)me->query("family/family_name") != "ؤ��")
                return notify_fail("�㲻��ؤ��������ôѧ��Ľ���ʮ���ƣ���\n");

        if( (int)me->query_skill("strike") < 200 ||
            me->query_skill_mapped("strike") != "xianglong-zhang")
                return notify_fail("��ġ�����ʮ���ơ��������ң��޷�ʹ�á�����С���\n");

        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "xiaoyaoyou")
                        return notify_fail("������С���Ҫ��ң�ε���ϣ�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������С�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");

        me->clean_up_enemy();
        ob = me->select_opponent();
        if( !target->is_killing(me) ) target->kill_ob(me);
        msg = HIW  "$N˫���й��ɵĻ�����������ʮ���Ƶ���ʽ�����ļ��죡\n\n"HIY"��һ�ƣ������лڣ�\n\n$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڶ��ƣ��������죡\n\n"HIY"$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�����ƣ��������\n\n"HIY"$N����һ�С����������Ѹ���ޱȵ�����$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�����ƣ��轥��½��\n\n"HIY"$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�����ƣ�Ǳ�����ã�\n\n"HIY"$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�����ƣ�����󴨣�\n\n"HIY"$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�����ƣ�ͻ��������\n\n"HIY"$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڰ��ƣ��𾪰��\n\n"HIY"$N���һ����˫��ʹ�����𾪰��������һ�а����$n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ھ��ƣ���Ծ��Ԩ��\n\n"HIY"$Nʹ������Ծ��Ԩ������$n��$l��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ�ƣ�˫��ȡˮ��\n\n"HIY"$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮһ�ƣ���Ծ��Ԩ��\n\n"HIY"$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ���ƣ�ʱ��������\n\n"HIY"$N˫������ʹ����ʱ����������$n��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ���ƣ����Ʋ��꣡\n\n"HIY"$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ���ƣ��������ڣ�\n\n"HIY"$Nʹ�����������ڡ���˫�������������$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ���ƣ���ս��Ұ��\n\n"HIY"$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ���ƣ���˪������\n\n"HIY"$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ���ƣ�����ެ��\n\n"HIY"$Nʹ��������ެ����˫���������ϻ���$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "���һ�ƣ�������β��\n\n"HIY"$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -1500);
        me->start_busy(3);
        return 1;
}

