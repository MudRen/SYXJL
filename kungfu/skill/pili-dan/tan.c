// tan.c  ������ �����־���
//create bye cuer
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object obj; 
        int kill=0;
        
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("�������ֻ�ܶ�ͬ�ط��Ķ���ʹ�á�\n");
        if( !present("pili dan",me))
                return notify_fail("������û�д������������밵���ˣ�\n");
        if( (int)me->query_skill("pili-dan", 1) < 80 )
                return notify_fail("���������������죬����ʹ�á����־�����\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 30 )
                return notify_fail("����ټ�ʮ��ׯ�����ߣ��������������䰵����\n");
        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("����������̫�������ܷ��䰵����\n");
        msg = CYN "ͻȻ�Ӱ������һ��������������$n��\n"NOR;
        if (random(me->query_skill("pili-dan")) > target->query_skill("dodge")/3 )
        {
                me->start_busy(1);
                target->start_busy(1+random(1));
                damage = 2*(int)me->query_skill("pili-dan", 1);
                damage = damage/2 + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -100);
                 msg += HIR"���$n�����������У��ҽ�һ��������һ�ᣬ�˺�������\n"NOR;
        }
        else
        {
                me->start_busy(1);     
                target->start_busy(random(1));
                me->add("neili",-100);
                msg += CYN"����$p���������������㿪�ˡ�\n"NOR;
        }                                    
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        { 
                msg += CYN"$pû�з�������������Դ��\n"NOR;
        }                                                 
        else
        { 
                msg += HIR"$p�������������������ˣ�\n"NOR;
                kill = 1;                
        }
        message_vision(msg, me, target);
        obj = present("pili dan",me);
        destruct(obj);              
        if(kill==1)
           target->kill_ob(me);
        return 1;
}
