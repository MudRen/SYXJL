// duansi.c ���������ơ���˼�ơ�
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{ 
        object ob;
        string msg;
 
        if( !me->is_fighting() )
                return notify_fail("����˼�ơ�ֻ����ս����ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ����ö�˼��\n");     

        if( (int)me->query("neili") < 100 )
                return notify_fail("�����ڵ��������������á���˼�ơ���\n");

        if( (int)me->query_skill("wuluo-zhang", 1) < 100 )
                return notify_fail("������������Ʋ�����죬����ʹ�á���˼�ơ���\n");

        msg = HIY "$N˫Ŀ΢�գ�˫��һ�ϣ�ͻȻ�������������ƣ�\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

          me->add("neili", -250);
          me->start_busy(3);

        return 1;
}
