#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ��"HIW"������������"NOR"��\n");

        if(!me->is_fighting())
                return notify_fail(""HIW"������������"NOR"ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_neili") < 1000 )
                return notify_fail("�������������\n");

   if((int)me->query("neili") < 1000 )
     return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("taiji-jian", 1) < 150)
                return notify_fail("���̫�������𻹲������������Ķ�ˣ����ȫ����ô���ɱ��\n");

        me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIC"\n$N����Ծ����һ�׳��죬Х���н��ѳ��ʣ�\n"NOR,me,target);
message_vision(HIW"$NĬ�����������\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIY"$NĬ���մ������\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIM"$NĬ����ͣ�����\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIB"$NĬ����棡����\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HIM"$NĬ�����������\n"NOR,me,target);        
        me->set_temp("taiji-jian_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIR"$NĬ�������������\n"NOR,me,target);                
        me->set_temp("taiji-jian_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"\n$N�߽�ʹ�գ�������������ͷ���˿�$n��\n"NOR,me,target);        
        
        me->delete_temp("taiji-jian_perform");

        me->receive_damage("jing", 50);
        me->add("neili", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1);
        return 1;
}

