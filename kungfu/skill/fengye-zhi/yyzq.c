// һҶ֪��
// bye jfeng
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��һҶ֪�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query_skill("fengye-zhi",1) < 100)
                return notify_fail("���Ҷָ�Ļ�򲻹�����ʹ��һҶ֪��!\n");
        if((int)me->query_skill("finger") < 100)
                return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ��һҶ֪�����!\n");
        if((int)me->query("neili") < 700)
                return notify_fail("���������ڲ���, ����ʹ��һҶ֪��! \n");
        if((int)me->query("max_neili") < 500)
                return notify_fail("��������Ϊ����, ����ʹ��һҶ֪��! \n");
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ�������!\n");
        msg =
HIC "$Nʹ����Ҷָ������һҶ֪���ʮָ������ֻ������ָӰ
����$n��$nֻ�����޴��мܣ�������ʱ�Ѳ�������,
��֪���������죬�������ˡ�\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 )
        {
                msg +=  HIR "���$p��$Pָ������̴�д�Ѩ! \n" NOR;
                target->start_busy( (int)me->query_skill("fengye-zhi",1) / 40 + 2);
                me->add("neili", -150);
        }
        else
        {
                msg += HIY "$p���쳤Ц����֮�󼼣��������ң�����δ�䣬������ʮ�����⡣\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        return 1;
}
