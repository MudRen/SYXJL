// juedi.c ���ط���
// 1997.9.2   csy

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("���ط���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

                
    if( (int)me->query_skill("liangyi-jian",1)<80)
    return notify_fail("��������ǽ���������죬����ʹ�á����ط�������\n");
     if( (int)me->query_skill("xuantian-wuji",1)<80)
        return notify_fail("��������޼���������񣬲���ʹ�á����ط�������\n"); 
                        
    if( (int)me->query("neili",1)<500)
    return notify_fail("����������̫��������ʹ�á����ط�������\n");
                        
 msg=HIY "$N�����޷��Զ���ʹ�����������ǽ����е���ɽ���������ط�������\n"
HIG "ɲ�Ǽ����ذ�����ɳ��ʯ��������Ӱ��$n��ȫ��Ҫ����̣��򿳣�������ȥ��\n" NOR;
        if (random(me->query("neili")) > target->query("neili")/4 )
{
        me->start_busy(3);
                target->start_busy(random(3));
                
    damage= (int)me->query_skill("liangyi-jian",1);
         damage = damage + random(damage);
                
        target->receive_damage("jing",random( damage ));
        target->receive_wound("qi",damage);
        me->add("neili",-damage/10);
        if( damage < 20 ) msg += HIY"���$n��$N������һ�����ƺ�һ����\n"NOR;
else
if( damage < 55 ) msg += HIY"���$n��$N������������������һ������������\n"NOR;
else if( damage < 80 ) msg += RED"���$n��$N���ص����������������ܵ������׻�һ�㣬��������������\n"NOR;
else msg += HIR"���$n��$N�ġ����ط�������͸ǰ�ģ���ǰһ�ڣ��������ɳ�������\n"NOR;
}
else
{
         me->start_busy(1);
                msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
}
        message_vision(msg, me, target);

        return 1;
}


