// qishang ����
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i, j, damage;
    
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�ô��У�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
                
        if( (int)me->query_skill("qishang-quan", 1) < 100 )
                return notify_fail("�������ȭ��������죬��û�а취ȭ�����ˡ�\n");

        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("�����Ŀǰ������û�а취������һ�С�\n");

        i=random((int)(me->query_skill("qishang-quan",1)/30));
        if(i<1) i=1;
        if(i>7) i=7;
        msg = HIY "$N�����˹���ʹ��������ȭ�����ľ��У�"+chinese_number(i)+"���ޱ�ǿ����������Х������$n���ϸ���ҪѨ��\n"+HIC "$n���ᵤ��֮������������ײ����"+chinese_number(i)+"�ɾ���������\n"NOR;
        if (!(me->query("neili")<0)) me->add("neili",-i*30);
        if ((random(me->query_skill("force")) > target->query_skill("force")/2))
        {
                me->start_busy(1);
                target->start_busy(i);
                
                damage = (int)me->query_skill("qishang-quan", 1);
                
                damage = damage/2 + random(damage);
                
                target->receive_damage("qi", (int)((i*(2*damage))/6));
                target->receive_wound("qi", (int)((i*damage)/6));
                if (!(target->query("neili")<0)) target->add("neili",-i*20);
     
                msg += HIY"���$n���ܲ�ס$N��"+chinese_number(i)+"�־������������ص�ײ����"+GRN"\n($n"+HIR"���ܵ�������ʵ���ᡣ"+GRN")\n"NOR;
                
        } else 
        {
                me->start_busy(1);
                msg += CYN"����$pæ��������$P��"+chinese_number(i)+"�־�����������֮�����ڻ�֮���Ρ�\n"NOR;
                if (!(target->query("neili")<0)) target->add("neili",-i*50);
        }
        message_vision(msg, me, target);
        return 1;
}

