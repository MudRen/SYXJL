// liujian.c ������   �����뷢

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����뷢ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�������뷢��\n");
             
        if( (int)me->query_skill("liumai-shenjian", 1) < 120 )
                return notify_fail("��������񽣲�����죬����ʹ�������뷢��\n");
              
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫��������ʹ�������뷢��\n");
                        
        msg = CYN "$N����ԴԴӿ�������̡��������г塢�س塢�ٳ塢������������,$n������ס��\n��ʱ������������\n"NOR;
          me->add("neili", -1000);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(1);
               target->start_busy(random(3));
                
                damage = (int)me->query_skill("force", 1);
               
                damage = damage*2 + random(damage);
                
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage*4);
                  me->add("neili", -1000 );
                
                if( damage < 20 ) msg += HIY"���$n�ܵ�$N�Ľ������У��ƺ�һ����\n"NOR;
                else if( damage < 40 ) msg += HIY"���$n��$N�Ľ������У����١���һ������������\n"NOR;
                else if( damage < 80 ) msg += RED"���$n��$N�Ľ������У��ؿ������ܵ�һ���ش�����������������\n"NOR;
                else msg += HIR"���$n��$N�Ľ������У�����[��]���³�һ����Ѫ�������絾����һ�����ɳ�������\n"NOR;
               
        } else 
 
 
        {
               me->start_busy(3);
                msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

