//By Hate@FC��.

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
                return notify_fail(HIC"��Ҫ��˭ʩչ����"HIY"����ת���ǡ�"HIC"��\n"NOR);

        if(!me->is_fighting())
                return notify_fail(HIY"����ת���ǡ�"HIC"ֻ����ս����ʹ�ã�\n"NOR);

        if((int)me->query("max_neili") < 1000 )
                return notify_fail("���������Ϊ̫�\n");

   if((int)me->query("neili") < 1000 )
     return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("murong-jianfa", 1) < 200)
                return notify_fail("���Ľ�ݽ���������죬�޷�ʹ�ý�ת���ǣ�\n"); 

        if( (int)me->query_skill("sword", 1) < 180 )
                return notify_fail("��Ļ�������������죬����ʹ�ý�ת���ǡ�\n");

message_vision(HIR"\n$N��Ȼ����һת���������������棬ֻ���߶佣���������ֱ�Ϯ��$n���ߴ�ҪѨ��\n"NOR,me,target);
message_vision(HIW"��תһ����"WHT"��"HIY"������"WHT"��\n\n"HIG"ֻ��$N����֮����һ������ֱ����$n�����壬$nֻ������һʹ���漴"HIC"������Ѩ��"HIG"�����޷����ݵľ�����ʹ��\n"NOR,me,target);        
          COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HIM"�Ƕ��ּ���"WHT"��"HIY"��ѣ��"WHT"��\n\n"HIG"ֻ��$N�����ٶ�����ֱ����$n�ļ�ͷ��$nֻ������һʹ���漴"HIC"���羮Ѩ��"HIG"����һ����Ҵ�ʹ��\n"NOR,me,target);        
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(MAG"ת�Ǽ�����"WHT"��"HIY"�����"WHT"��\n\n"HIG"ֻ��$N�������ϣ������ֳ�����Ȼ�������ܵĴ���$n����ף�$nֻ����΢һʹ���漴"HIC"��ӿȪѨ��"HIG"����һ�������ʹ��\n"NOR,me,target);        
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));message_vision(YEL"��ת�Ķ���"WHT"��"HIY"��Ȩ��"WHT"��\n\n"HIG"ֻ��$N�������ǣ���ֱ����$n�����壬$nֻ�����ϱ�һ���Ҵ̣��漴�е�"HIC"��������Ѩ��"HIG"����һ�������ʹ��\n"NOR,me,target);   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIB"�������У�"WHT"��"HIY"�����"WHT"��\n\n"HIG"ֻ��$N����ƫ�棬��ֱ����$n�����࣬$nֻ������һ�����漴"HIC"������Ѩ��"HIG"��Ȼ���Ѫ����\n"NOR,me,target);           COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(RED"�Ǿ�������"WHT"��"HIY"������"WHT"��\n\n"HIG"ֻ��$N�������ϣ����϶��´���$n��ͷ����$nͻȻ����ȫ�������������漴��Ѩ"HIC"���ٻ�Ѩ��"HIG"��Ȼ��ʹ�ޱȣ�"NOR,me,target);  COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIR"��ת���ƣ�"WHT"��"HIY"ҥ����"WHT"��\n\n"HIG"ֻ��$N������������������������$n�������㣬�ཫ$n�ĵ�һ��Ѩ"HIC"��̫��Ѩ��"HIG"��������Ѫ����\n"NOR,me,target);                       
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(WHT"\n$N�������ǣ��ս�ͦ�����У�һ�����߷緶��Ȼ�������·��������$n�Ĵ��ڡ�\n"NOR,me,target);        
        
//        target->receive_damage("jing", 200)
        target->receive_damage("qi", 200+(int)me->query("max_neili")/2);
        me->receive_damage("jing", 50);
        me->add("neili", -500);

        me->start_busy(5);
        return 1;
}
