#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query("family/master_name")!="��ɽͯ��")
                return notify_fail("��û�о�����ɽͯ�ѵ�ָ�㣬�޷�������еľ��裡\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����־���\n");
             
        if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
                return notify_fail("��������Ʋ�����죬����ʹ�á����־���\n");
              
        if( (int)me->query("neili", 1) < 5000 )
                return notify_fail("����������̫��������ʹ�á����־���\n");
                        
        msg = HIC "$NĬ���񹦣�ʹ����ɽ�����ơ����־�����ͼ����������$n"NOR;
          me->add("neili", -3000);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(8);
               target->start_busy(random(1));
                
                damage = (int)me->query_skill("force", 1);
               
                damage = damage*2 + random(damage);
                
                target->receive_damage("qi", damage/4);
                target->receive_wound("qi", damage/2);
                  me->add("neili", -3000 );
                
                if( damage < 20 ) msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
                else if( damage < 40 ) msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
                else if( damage < 80 ) msg += RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
                else msg += HIC"���$n��$N������һ��  ���¼�����Ѫ��������ʵ���ᣡ\n"NOR;
               
        } else 
 
 
        {
               me->start_busy(10);
                msg += HIC"����$p������$P����ͼ����û���ϵ���\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

