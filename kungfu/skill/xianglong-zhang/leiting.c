//leiting.c -��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);


        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʩչ��������������\n");

          if (me->query_skill_mapped("force") != "huntian-qigong" || me->query_skill("force",1)/2 + me->query_skill("huntian-qigong",1) < 135 )
                return notify_fail("����ڹ��ȼ��������޷�ʩչ��������������");

        if (me->query_skill("strike",1)/2 + me->query_skill("xianglong-zhang", 1) < 135 )
                return notify_fail("��Ľ���ʮ���Ƶȼ�������ʩչ��������������\n");

      if (me->query("neili")<200||me->query("max_neili")<200)
                return notify_fail("��������������޷�ʩչ��������������");
        msg = RED "$Nȫ����������Խ��һʽ����������������������$n��";

me->start_busy(3);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")) {
                msg += "���$p��$P���˸����ֲ�����\n" NOR;
                message_vision(msg, me, target);
                target->unconcious();
        } else {
                msg += "����$p���Ƕ����$P�����һ������\n" NOR;
                message_vision(msg, me, target);
//                 me->unconcious();
      me->set("neili",(me->query("neili")-200));
        }
        return 1;
}
