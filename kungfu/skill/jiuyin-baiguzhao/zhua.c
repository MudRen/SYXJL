// zhua.c  �����׹�צ������һ����
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
    	string msg;
	if( !target ) target = offensive_target(me);
	if ((string)me->query("gender")!="Ů��")
		return notify_fail("����⹦��û�����ֹ��ܡ�\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("������һ����ֻ����ս����ʹ�á�\n");

	if(!target || !target->is_character()|| !me->is_fighting(target) )
		return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 if(!me->query("jiuyin"))// && (int)me->query_skill("bibo-shengong", 1) < 100 )
		return notify_fail("�㲻��ʹ�á�����һ������\n");

    if( (int)me->query("shen", 1) > 0)
        return notify_fail(WHT"�����������ʿ���������á�����һ�������������书��\n"NOR);

    if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 100 )
        return notify_fail(WHT"��ľ����׹�צ������죬��ʹ����������һ������\n"NOR);
        
        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");

    if( (int)me->query_skill("force", 1) < 100 )
        return notify_fail(RED"����ڹ��ķ���򲻹���ʹ�á�����һ�����������Լ��ľ�����\n"NOR);

    msg = HIC "$NͻȻ��˫�Ʊ�צ������ǰ��Ȼ����糵�㼱ת��Ȧ������ʩչ��������һ������˫צ��  ��һ�����������$n��ת��Ȧ���ֻص�ԭ�ء�\n"NOR;

    if (random(me->query_skill("force")) > target->query_skill("force")/2||
        random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));

        damage = (int)me->query_skill("jiuyin-baiguzhao", 1);

        damage = damage + random(damage);

        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage/2);
        target->receive_damage("jing", damage/2);
        target->receive_wound("jing", damage/4);
        me->add("neili", -damage/3);

   msg += HIC"ԭ��$N����$nͷ��������������������ָ����\n$nֻ����ͷ��һ�������������������һ���ˡ�����������\n"NOR;
    } else
    {
        me->start_busy(4);
        msg += HIY"����$p������$P����ͼ������ͷ������һ�ߡ�\n"NOR;
    }
     message_vision(msg, me, target);

    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}


