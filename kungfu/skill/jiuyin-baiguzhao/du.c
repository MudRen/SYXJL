// /kungfu/skill/jiuyin-baiguzhao/du.c �����׹�צʩ��
// adx 22:44 99-2-10

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
//        object obj;
        string msg;

        if( !target ) target = offensive_target(me);
   	if ((string)me->query("gender")!="Ů��")
        	return notify_fail("����⹦��û�����ֹ��ܡ�\n");

        if( environment(me)->query("no_fight") )
              return notify_fail("ʩ��ֻ����ս����ʹ�á�\n");
        if(!target || !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("ʩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

if(!me->query("jiuyin") && (int)me->query_skill("bibo-shengong", 1) < 100 )
                return notify_fail("�㲻��ʹ��ʩ��������\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 100 )
                return notify_fail("��ľ����׹�צ������죬����ʩ����\n");

                msg = HIB "$N����������ָ�ϣ�˫����ָ΢΢�������⣬ץ��$n��\n";

        me->start_busy(2);
        if( random( (int)me->query_skill("jiuyin-baiguzhao",1))
          > random(target->query_skill("dodge") ) ) {
                msg += HIB " ���$p��$Nץ��һ��������"+HIR"Ѫ�ۣ�\n" NOR;
            target->receive_damage("qi",(int)me->query_skill("jiuyin-baiguzhao",1));
            target->receive_wound("qi",15 + random(10));
            target->receive_wound("jing", 10);
            target->apply_condition("jy_poison", random(me->query_skill("jiuyin-baiguzhao",1)/5) + 1 +
                        target->query_condition("jy_poison"));
                        target->start_busy(random(2));
        } else {
                msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
                me->start_busy(random(4));
        }
        message_vision(msg, me, target);
        return 1;
}

