// zhong.c ��������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("������ֻ�����ڶ������ϡ�\n");

         if ((me->query_skill("bahuang-gong", 1) < 250 ) && (me->query_skill("beiming-shengong", 1) < 40 ))
              return notify_fail("����ڹ��ķ�������죬��������������\n");

        if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
                return notify_fail("�����ɽ�����Ʋ�����죬��������������\n");

        if (!objectp(obj=present("jiudai", me)))
            return notify_fail("������û�оƴ������ܻ�ˮΪ����\n");

          msg = HIW "$N��ˮΪ�����������У���ƮƮ������$n��\n";

        me->start_busy(1);
        if( random( (int)me->query_skill("liuyang-zhang",1))
          > random(target->query_skill("dodge") ) ) {
                    msg += HIG " ���$p��$P���˸����ţ�$p����$P���������ˣ�\n" NOR;
                  target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1));
                target->receive_wound("qi",55 + random(10));
                target->receive_wound("jing", 30);
                target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + 1 +
                target->query_condition("ss_poison"));
                me->start_busy(random(4));
        } else {
                msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        target->start_busy(1 + random(2));
        if( !target->is_killing(me) )
                target->kill_ob(me);
        destruct(obj);

        return 1;
}
