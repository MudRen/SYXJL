// feixue.c �����ѩ 

#include <ansi.h>
#include <weapon.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage, attp, defp;
        object obj;
        string w_name;

        w_name = me->query("weapon/name");
        obj = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�������ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("liangyi-jian", 1) < 60)
   return notify_fail("��������ǽ���������죬�޷�ʹ�����ǽ�����֮һ�ġ������ѩ����\n");

        if ((int)me->query_skill("xuantian-wuji", 1) < 70)
                return notify_fail("��������޼������̫ǳ���޷�ʹ���������ѩ����\n"); 
         if ((int)me->query_skill("throwing", 1) < 60)
                return notify_fail("��ġ��������������̫ǳ���޷�ʹ���������ѩ����\n"); 
        if ((int)me->query("neili",1) < 300)
                return notify_fail("��������������޷�ʹ�����ǽ��С������ѩ���ľ�����\n"); 
        message_vision( HIW "$N���һ���������ڽ���Ĭ��������ֻ�������һ�������Ϊ֮һ�ϣ����������㣬$N����\n"
         + "��������Ϊ������Ƭ���������ѩ����$n���������\n"NOR, me, target );

        attp = me->query_skill("xuantian-wuji",1) + me->query_skill("liangyi-jian",1);
        defp = target->query_skill("dodge");

        if( random( attp ) > random( defp ) )
        {
                damage = me->query_skill("liangyi-jian",1) + (int)me->query_skill("xuantian-wuji", 1)*2;
                damage = damage - random( target->query_skill("dodge")/3 );

                if( objectp(obj)&&w_name!=obj->query("name") )
                {
                        target->receive_wound("jing", random( damage/2 ))*3;
                        target->receive_damage("qi", 20 + random(damage))*3;
                        target->receive_wound("qi", 20 + damage)*3;

                        target->start_busy(3 + random(10));
                }
                else
                {
                        target->receive_wound("jing", random( damage/2 ));
                        target->receive_damage("qi", 20 + random(damage));
                        target->receive_wound("qi", 20 + damage);

                        me->start_busy(3);
                        target->start_busy(3 + random(4));
                }
        }
        else {
                message_vision( HIY "$p���Ų�æ�ػζ����Σ�˲ʱ�����˽��ꡣ\n" NOR, me, target );
                me->start_busy(5);
        }

        if( !target->is_killing(me) ) target->kill_ob(me);

        me->add("neili", -150);

        if( objectp(obj) && w_name!=obj->query("name") )
        {
                me->set("weapon/make",0);
                destruct( obj );
                me->delete("weapon");
                me->save();
        }
        else destruct( obj );

        return 1;
}

