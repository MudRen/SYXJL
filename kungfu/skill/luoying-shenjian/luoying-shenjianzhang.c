// shenjian.c �һ�Ӱ�����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage, rand;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�һ�Ӱ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!(me->query("thd/perform") & 2))
                return notify_fail("����Ȼ��˵�����һ�Ӱ����񽣡���һ�У�����ȴδ���ڡ�\n");

        if( (int)me->query_skill("luoying-zhang", 1) < 80 )
                return notify_fail("�����Ӣ���Ʋ�����죬�޷�ʹ���һ�Ӱ����񽣡�\n");

        if ( (int)me->query("neili") < 120)
                return notify_fail("��������������޷�ʹ���һ�Ӱ����񽣡�\n");

        msg = CYN "$N˫��������Ե���ƽ��棬��Ȼ����˿˿�Ľ��������������߷��$n��\n";

        rand = random(me->query("combat_exp"));
        if( rand > (int)target->query("combat_exp")/2 ) {
                msg += "$n����������������ͬʱ���У�\n";
                damage = (int)me->query_skill("luoying-zhang", 1);
                damage += random(damage / 2);
                if (damage > target->query("neili") / 8)
                        damage -= target->query("neili") / 15;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                if( damage < 40 ) msg += HIY"$n����ɫ��䣬������ʹ���̡�\n"NOR;
                else if( damage < 80 ) msg += HIR"$n����Ϣ��Ȼһ�ͣ�ȫ���ƺ���Ҫ̱�ˣ�\n"NOR;
                else msg += RED"$n�����ؿڣ����ۡ���һ���³���һ����Ѫ��\n"NOR;
                message_vision(msg, me, target);
        } 
        else if( rand > (int)target->query("combat_exp")/3 ) {
                msg += "$n�����һ�ƣ������޷��㿪��һ�ƣ�\n";
                damage = (int)me->query_skill("luoying-zhang", 1);
                damage = damage / 2 + random(damage / 2);
                if (damage > target->query("neili") / 10)
                        damage -= target->query("neili") / 15;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                if( damage < 40 ) msg += HIY"$n����ɫ��䣬������ʹ���̡�\n"NOR;
                else if( damage < 80 ) msg += HIR"$n����Ϣ��Ȼһ�ͣ�ȫ���ƺ���Ҫ̱�ˣ�\n"NOR;
                else msg += RED"$n�����ؿڣ����ۡ���һ���³���һ����Ѫ��\n"NOR;
                message_vision(msg, me, target);
        } 
        else {
                msg += "$n���һ�����˲�������־����п�����������У������ų���һ���亹��\n" NOR;
                message_vision(msg, me, target);
        }
        me->add("neili", -80);
        me->start_busy(1);

        return 1;
}
