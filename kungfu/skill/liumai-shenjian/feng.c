// feng.c ������ - ��
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
                return notify_fail("���⡹�־�ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                        return notify_fail("�㲻��ʹ��������\n");

        if( (int)me->query_skill("liumai-shenjian", 1) < 90 )
                return notify_fail("���������̫���裬����ʹ�á��⡹�־���\n");

        if ( me->query("neili") < 300)
                return notify_fail("������������������޷�ʹ�á��⡹�־���\n");
        me->add("neili", -30);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
                
        msg = HIY "$N����һ������ʹ�������񽣡��⡹ʽ��ָָ��㣬�����糱������\n";

          me->start_busy(3);
        me->add("neili", -30);
          if( random( me->query("neili") + me->query("dodge") * 10 ) > random((int) target->query("dodge") * 10) ) {
                msg += HIR " $pǿ�����������ҵ����޷����֣�\n" NOR;
                target->start_busy( (int)me->query_skill("liumai-shenjian", 1) / 20 );
        } else {
                msg += "����$p����һ����ƮȻ����$P�Ĺ�����\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
