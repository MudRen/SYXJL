// wenrou.c ����һ��

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
                  return notify_fail("������һ����ֻ����ս����ʹ�á�\n");
 
          if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                  return notify_fail("������һ������ʼʱ�����е����֣�\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");

          if( (int)me->query_skill("blade") < 50 || me->query_skill_mapped("blade") != "ruyi-dao")
                  return notify_fail("��ĵ��������ң��޷�ʹ������һ����\n");

            msg = HIR "$Nʹ�����⵶����"+HIM"������һ����"NOR""HIR"�����溮â���䣡\n" NOR;
        message_vision(msg, me);

        weapon = me->query_temp("weapon");

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -200);
        me->start_busy(random(5));

        return 1;
}


