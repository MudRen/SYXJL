
// yihuanghu.c ���㱾�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("qishang-quan",1) + me->query_skill("jiuyang-force",1);

        if( !me->is_fighting() )
                return notify_fail("�����㱾���ֻ����ս����ʹ�á�\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("��������������ߣ�\n");

        if( (int)me->query_skill("cuff") < 150 )
                return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���\n");

        if( (int)me->query_skill("qishang-quan", 1) < 150)
                return notify_fail("������ȭ����Ϊ���������ܹ�������㱾�! \n");

          if( (int)me->query_skill("shenghuo-shengong", 1) < 150)
                  return notify_fail(HIM "���ʥ������Ϊ���㣬�������ʹ�����㱾�! \n" NOR);

        if( me->query_skill_mapped("cuff") != "qishang-quan")
                return notify_fail("��û�м�������ȭ���޷��������㱾���\n");

        msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "���㱾�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 4;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-300);

                msg = HIC "���$N˫ȭ����ʱ��ȴ���������ޡ�\n$n������ּ䣬�ѱ�$N��������ס������лк����ģ�\n"NOR;
                target->start_busy((int)skill/20);
                me->start_busy(2);
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
