// /kungfu/skill/gu.c ��עһ��
// adx 23:33 99-2-11
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

                damage = (int)me->query_skill("bibo-shengong", 1);

                damage = random(damage)*10;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����עһ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á���עһ������\n");               

        if( (int)me->query_skill("cuixin-zhang", 1) < 60 )
                return notify_fail("��Ĵ����Ʋ�����죬����ʹ�á���עһ����!\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á���עһ����!\n");

        msg = CYN "$NĬ���񹦣�ʹ������עһ������˫��ƽ�ƹ���$n��\n"NOR;

        if (random(me->query_skill("cuixin-zhang")) > target->query_skill("force")/3 )
        {
                me->start_busy(random(2));
                target->start_busy(random(3));

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage/3);

                if( damage < 40 )
                        msg += HIY"���$n��$N˫�ƴ����ؿڣ��ƺ�һ����\n"NOR;
        else if( damage < 80 )
                        msg += HIY"���$n��$N��˫�ƴ����ؿڣ����١���һ������������\n"NOR;
        else if( damage < 160 )
                        msg += RED"���$n��$N��˫�ƴ����ؿڣ������ܵ�һ���ش�����������������\n"NOR;
                else
                        msg += HIR"���$n��$N��˫�ƴ����ؿڣ���ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
                
        }
        else 
        {
                me->start_busy(random(2));
                me->add("qi", -(damage/2));
                me->add("eff_qi", -(damage/5));
                msg += CYN"����$p������$P����ͼ������һת�����ƻػ���\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
