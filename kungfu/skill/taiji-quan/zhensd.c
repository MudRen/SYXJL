// zhen.c ̫��ȭ�����־�
// snowman
#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����־���\n");         
        if( (int)me->query_skill("taiji-quan", 1) < 100 )
                return notify_fail("���̫��ȭ������죬����ʹ�á����־���\n");
        if( (int)me->query_skill("yinyun-ziqi", 1) < 100 )
                return notify_fail("����������ȼ������ߣ��������������˵С�\n");
        if( (int)me->query("max_neili", 1) < 1200 )
                return notify_fail("����������̫��������ʹ�á����־���\n");                
        if( (int)me->query("neili", 1) < 1200 )
                return notify_fail("��������������������ʹ�á����־���\n");
       
        if (me->query_skill_prepared("cuff") != "taiji-quan"
           || me->query_skill_mapped("cuff") != "taiji-quan")
                return notify_fail("�������޷�ʹ��̫��ȭ�����־����й�����\n");                                                                                 
        if (me->query_skill_mapped("parry") != "taiji-quan")
                return notify_fail("��̫��ȭ�����־������ڼ����мܵ�����²���ʹ�á�\n");                                                                                 
                    
               
        msg = CYN "$NĬ���񹦣�ʹ��̫��ȭ"RED"����"CYN"�־�����������̫��Ȧ��ס$n����ͼ�Ա�����������$n��\n"NOR;

        if(me->query("neili") < target->query("neili")){
           me->start_busy(3);
           target->start_busy(3); 
           me->add("qi", -50);
           me->add("neili", -300);
           target->add("qi", -50);
           target->add("neili", -300);
           msg += HIY"���$p��$P��������һƴ��˫����ûռ��˿���ô���\n"NOR;
           }
        else if(random(me->query_skill("force")) > target->query_skill("force")/2){
                me->start_busy(3);
                target->start_busy(2+random(3));
                
                damage = (int)me->query_skill("force")*2;                
                if(me->query_skill("taiji-quan", 1) > random(target->query_skill("parry", 1)))
                   damage = damage+me->query_skill("taiji-quan", 1);
                if(me->query_skill("taiji-quan", 1) > random(target->query_skill("dodge", 1)))
                   damage = damage+target->query_skill("dodge", 1);                
                if(me->query("neili") > target->query("neili")*2)
                   damage = damage+me->query_skill("force");
                if(damage> 1100) damage = 1100;                

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/4);
                if(target->query("neili") >= damage) {
                   target->add("neili", -(damage/2));
                target->add("qi", -50);
                }
                else {
                target->set("neili", 0);
                me->add("neili", -(damage/3));
                me->add("qi", -50);
                  }
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";       
                } 
        else{
             me->start_busy(3);
             me->add("qi", -25);
             me->add("neili", -300);
             msg += HIY"����$p������$P����ͼ����û���ϵ���\n"NOR;
             }
        message_vision(msg, me, target);
        return 1;
}
