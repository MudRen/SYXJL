// ����Ū��Ӱ
// bye jfeng
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    string msg;
        if( !me->is_fighting() )
            return notify_fail("������Ū��Ӱ��ֻ����ս����ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
        if((int)me->query_skill("murong-xinfa",1) < 100)
                return notify_fail("���Ľ���ķ���򻹲�����, ����ʹ����һ���� !\n");
        if((int)me->query_skill("sword",1) < 100)
                return notify_fail("��Ļ���������򻹲�����, ����ʹ����һ���� !\n");
        if((int)me->query_skill("piaoyi-jianfa",1) < 100)
                return notify_fail("���Ʈ�ݽ�����򻹲�����, ����ʹ����һ���� !\n");
        if( (int)me->query("neili") < 700 )
                return notify_fail("�������������\n");
        if( (int)me->query("max_neili") < 700 )
                return notify_fail("���������Ϊ������\n");
    msg = 
HIC "\n$N��̾һ�����ֵ�����������Ʈ��������ʹ������Ʈ�ݽ����ľ���������Ū��Ӱ����\n" NOR;
        message_vision(msg, me);
        me->clean_up_enemy();
        ob = me->select_opponent();
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili",-random(150)-50);
    return 1;
}
