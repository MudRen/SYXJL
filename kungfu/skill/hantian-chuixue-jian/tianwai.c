#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

        if(!me->is_fighting())
              return notify_fail("��������ɡ�ֻ����ս����ʹ�ã�\n");

        if((int)me->query("neili") < 1500 )
                return notify_fail("�������������\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("�������������\n");
       

        if(me->query("family/master_name")!="��ɽͯ��")
                return notify_fail("��û�о�����ɽͯ�ѵ�ָ�㣬�޷�������еľ��裡\n");
        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");


        if((int)me->query_skill("hantian-chuixue-jian", 1) < 150)
                return notify_fail("��ĺ��촵ѩ�����ȼ��������޷�ʹ�á�������ɡ���\n");
 
        if((int)me->query_skill("bahuang-gong", 1) < 150)
                return notify_fail("��İ˻Ĺ��ȼ��������޷�ʹ�á�������ɡ���\n");
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           
           message_vision(HIB"\nͻȻֻ��$Nʹ�����촵ѩ�����ռ�������������ɡ���\n"NOR, me);
                      me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIB"$N��Х�����죡����\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HIM"$N��Х�����⣡����\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIR"$N��Х�����ɣ�������\n"NOR,me,target);                
        me->set_temp("taiji-jian_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"$N��Х�����ɣ�������\n"NOR,me,target);                
        me->set_temp("taiji-jian_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));  
           message_vision(HIW"\n$N������δ��,������������籩��֮������$n��ȥ��\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N�޷�������Ϣ������ֻ�ú�Ծ���С�\n"NOR, me, weapon);

           me->delete("lingshe");

           me->add("neili", -100);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(4);
   return 1;
}


