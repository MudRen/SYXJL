// jingsuck.c


#include <ansi.h>

int exert(object me, object target)
{
        int sp, dp;

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("��Ҫ��ȡ˭�ľ���\n");

        if ( me->query_temp("sucked") )
                return notify_fail("��ո���ȡ������\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʩ�ñ�ڤ�����˾�����\n");


        if( (int)me->query_skill("beiming-shengong",1) < 30 )
                return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է��ľ���\n
");

        if( (int)me->query("neili",1) < 10 )
                return notify_fail("�����������������ʹ�ñ�ڤ�񹦡�\n");

        if( (int)target->query("jing") < (int)target->query("max_jing") / 5 )
                return notify_fail( target->name() +
                        "�Ѿ������ɢ�����Ѿ��޷�����������ȡ�����ˣ�\n");

        message_vision(
                HIR "$NͻȻ���ص�һЦ��˫��һǰһ���׼$n��̫��Ѩ���˹�����\n"
 NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query("ka
r");
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

        me->set_temp("sucked", 1);

        if( random(sp) > random(dp) )
        {
                tell_object(target, HIR "���;������������̰��ʹ����־����\n" NOR);
                  tell_object(me, HIG "�����" + target->name() + "�ľ���������ԴԴӿ������\n" NOR);

        target->receive_damage("jing", (int)me->query_skill("beiming-shengong", 1) );
                me->add("jing", (int)me->query_skill("beiming-shengong", 1) );

                if( target->query("combat_exp") >= me->query("combat_exp") ) {
       if( (int)me->query("potential") - (int)me->query("learned_points") < 300
)
                                me->add("potential", 1);
                }

                me->start_busy(random(3));
                target->start_busy(random(3));
                me->add("neili", -5);

                call_out("del_sucked", 2, me);
        }
        else
        {
                message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->start_busy(3);
                call_out("del_sucked", 4, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}

