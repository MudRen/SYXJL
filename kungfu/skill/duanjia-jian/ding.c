// qidingshanhe.c  �μҽ��� [����ɽ��]

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
            return notify_fail("���μҽ���������ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if((int)me->query_skill("kurong-changong",1) < 100)
                return notify_fail("��Ŀ�����������Ϊ����, ����ʹ����һ���� !\n");

        if((int)me->query_skill("dodge") < 135)
                return notify_fail("����Ṧ��Ϊ����, ����ʹ�öμҽ������У�\n");
 
        if((int)me->query_skill("sword") < 135)
                return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�öμҽ�������! \n");

    if( (int)me->query("neili") < 1200 )
                return notify_fail("�������������\n");


     msg = HIG "$Nʹ���μҽ����ľ���������ɽ�ӡ������һ��������������Ȼ�ӿ죡" NOR;
    message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
                me->add("neili", -50);
          me->start_busy(4);

    return 1;
}
