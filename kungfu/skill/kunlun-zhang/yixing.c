// yixing.c ���δ�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{
        int damage;
        string msg;
        string limb,*limbs,attack_skill,attack;
        object weapon;
        mapping my,your,action;
        if( !target ) target = offensive_target(me);

        if(!target||!target->is_character() || !me->is_fighting(target) )
        return notify_fail("���δ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

                
        if( (int)me->query_skill("kunlun-zhang",1)<100)
        return notify_fail("��������Ʋ�����죬����ʹ�á����δ󷨡���\n");
        if( (int)me->query_skill("xuantian-wuji",1)<100)
        return notify_fail("��������޼���������񣬲���ʹ�á����δ󷨡���\n");
                                
                        
        if( (int)me->query("neili",1)<600)
        return notify_fail("����������̫��������ʹ�á����δ󷨡���\n");
                        
        msg=CYN"$N������Σ�ʩչ�����δ󷨡��񹦣���\n"NOR;

        me->start_busy(3);
                target->start_busy(random(3));
                
        damage = (int)me->query_skill("kunlun-zhang",1);
                
                damage = damage/2 + random(damage);
                
        target->receive_damage("jing",random( damage/2 ));
        target->receive_wound("qi",damage/3);
        me->add("neili",-damage/10);
                
        weapon=target->query_temp("weapon");
        if(objectp(weapon))     attack_skill=weapon->query("skill_type");
        else                            attack_skill="strike";
        attack=target->query_skill_mapped(attack_skill);
        if(!attack)     attack=attack_skill;
        msg +=CYN"$NͻȻʹ��$n��ѧ��"+to_chinese(attack)+"���Ա�֮����ʩ������\n"NOR;
        my=target->query_entire_dbase();
        your=me->query_entire_dbase();
                limbs=target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        action=target->query("actions");
        if( !mapp(action) ) {
                target->reset_action();
                action=target->query("action");
                if( !mapp(action) ) {
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"),
        target->query("actions",1)));
                        return 0;
                }
        }
        msg += action["action"]+"��\n";
        msg+=RED"$n����ʧ��֮�ж��������������$l���"+action["damage_type"]+"����\n\n"NOR;
        msg=replace_string(msg,"$l",limb);
        if(objectp(weapon)) msg=replace_string(msg,"$w",weapon->name());
        msg +=RED"$n����ʧ��֮�ж���������ֻ����ǰһ�ڡ�\n"NOR;
        message_vision(msg, me, target);

        return 1;
}
