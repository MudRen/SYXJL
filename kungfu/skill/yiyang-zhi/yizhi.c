// yizhi.c һ��ָ ��һָ��Ǭ����
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query_str() < 28)
                return notify_fail("���������,����ʹ����һ����!\n");

        if((int)me->query_skill("kurong-changong",1) < 100)
                return notify_fail("����������Ĺ�����������ʹ��!\n");

        if((int)me->query_skill("finger") < 120)
                return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ�á�һָ��Ǭ��������!\n");

        if((int)me->query("neili") < 300)
                return notify_fail("���������ڲ���, ����ʹ�á�һָ��Ǭ����! \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ�������!\n");

        msg = HIY "$Nʹ��һ��ָ������һָ��Ǭ��������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n"NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
        {
                msg +=  HIG "���$p��$P���˸����ֲ���! \n" NOR;
                target->start_busy( (int)me->query_skill("yiyang-zhi",1) / 15 + 3);
                me->add("neili", -100);
        }
        else
        {
                msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}


