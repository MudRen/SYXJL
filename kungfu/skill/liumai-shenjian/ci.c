// ci.c ������ - ��
// Written by Doing Lu 1999/1/4

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int lvl;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���̡��־�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                        return notify_fail("�㲻��ʹ��������\n");

        lvl = (int) me->query_skill("liumai-shenjian", 1);
        if( lvl < 100 )
                return notify_fail("���������̫���裬����ʹ�á��̡��־���\n");

        if ( me->query("neili") < 400)
                return notify_fail("������������������޷�ʹ�á��̡��־���\n");
        me->add("neili", -40);


        msg = HIG "$Nʹ�������񽣡��̡�ʽ��ָ������ʱ�佣���ݺᣬ��$n��Χ���ڡ�\n";

        me->start_busy(2);
        if( random( me->query("neili") + me->query("liumai-shenjian") * 10 ) > random((int) target->query("neili") + (int) target->query("dodge") * 10)) {
                msg += HIR " ���$pһ���ƺߣ�����������\n" NOR;
                target->receive_damage("qi", random(lvl) + lvl);
                target->receive_wound("qi", random(lvl));
        } else {
                msg += "����$p�����мܣ�������ס��$P���ơ�\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

