// nizhuan.c ��ת����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( !target ) target = me;
        
        //if(me->query("oyf_hamagong") < 2) 
          //      return notify_fail("���˸�󡹦ʹ������ת����������\n");
        if((int)me->query("neili") < 300  ) 
                return notify_fail("�������������\n");
        if((int)me->query("jingli") < 200  ) 
                return notify_fail("��ľ���������\n");
        if((int)me->query_temp("nizhuan") ) 
                return notify_fail("���Ѿ������˾�����\n");

        skill = me->query_skill("force") / 2;
        skill = skill + me->query_skill("hamagong");
        skill = skill / 2;
        me->add("neili", -200);
        me->add("jingli", -20);
        me->receive_damage("qi", 0);

        message_vision(
        HIW "$N˫�ֳŵأ����з���һ���ܵͺ�����һ�ɹ��ھ�����ʹ$N˫����أ���ͷ������֮�ơ�\n" NOR, me);
        tell_object(me, HIW "��о����ڸ�󡹦�������ת�������йɾ޴������Ҫ��������һ����\n" NOR);

        me->add_temp("apply/parry", skill);
          me->add_temp("apply/strength",skill/2);
        me->set_temp("nizhuan", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
          me->add_temp("apply/strength", - amount/2);
            me->add_temp("apply/parry",- amount);
        me->delete_temp("nizhuan");
        tell_object(me, HIW "����ת�����˹����ã������ֽ�����ԭ��\n" NOR);
}

