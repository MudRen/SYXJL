// xiangsi.c ���������ơ���˼������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��˼ֻ�ܶ�ս���еĶ���ʹ�á�\n");           

        if( (int)me->query_skill("wuluo-zhang", 1) < 80 )
                return notify_fail("������������Ʋ�����죬����ʹ�á���˼����\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");  

        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("����������̫��������ʹ�á���˼����\n");

        msg = CYN "ֻ��$N��ð���̣�ʹ�������������еġ���˼��������˫��Ӳ��$n��\n"NOR;

          me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR " ���$p��$P���˸����ֲ�����\n" NOR;
                target->start_busy( (int)me->query_skill("wuluo-zhang") / 20 );
        } else {
                msg += CYN"����$p������$P�����⣬���׵Ķ㿪�ˡ�\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
