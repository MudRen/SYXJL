// /kungfu/skill/hua.c ��Ӣ���� �ƺ�����
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
                return notify_fail("���ƺ����롹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("luoying-shenjian", 1) < 60 )
                return notify_fail("�����Ӣ������������죬����ʹ�á����컨�꡹��\n");

        if( (int)me->query_skill("bibo-shengong", 1) < 160 )
                return notify_fail("��ı̲��񹦲�����죬����ʹ�á����컨�꡹��\n");

        msg = CYN "$N����һ����һʽ���ƺ����롹���������佣�������ݳ���\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
        {
                msg += CYN " ���$p��$P���˸����ֲ�����\n" NOR;
                attack_time = random((int)me->query_skill("luoying-shenjian", 1) / 30);
                if(attack_time < 1)
                        attack_time = 1;

                for(i = 0; i < attack_time; i++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

                me->start_busy(random(2));
                me->add("neili", -100);
        }
        else
        {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(random(3));
        }
        message_vision(msg, me, target);

        return 1;
}


