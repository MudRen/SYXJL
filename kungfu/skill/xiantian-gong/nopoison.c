#include <ansi.h>

int exert(object me, object target)
{
     if (target==me)
        {
        if( me->is_fighting())
                return notify_fail("ս�����޷��˹��ⶾ��\n");
        
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query_skill("xiantian-gong", 1) <80)
                return notify_fail("������칦���𻹲�����\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return
        notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
        write( CYN "���������£��������칦��ʼ�ⶾ��\n" NOR);
        message("vision",
                CYN + me->name() +
     "�������£��������칦�Ƴ����ڵĶ��ء����ã��³�һ�ں�Ѫ����ɫ�ö��ˡ�\n"
        NOR,
                environment(me), me);
        
        me->add("neili", -300);
        me->add("max_neili", -5); 
        me->clear_condition();
        return 1;
        }
      
      else{
       if( !target )
                return notify_fail("��ҪΪ˭�ⶾ��\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹��ⶾ��\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

       if((int)me->query_skill("xiantian-gong", 1) <100)
                return notify_fail("������칦���𻹲�����\n");

       if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
       return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
        return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ���������������\n");

        message_vision(
                CYN "$N�������£��������칦������������$n���ģ������ؽ���������$n����....\n\n"
                "���˲��ã�$N��ͷ��ð������ĺ��顣$n�³�һ�ں�Ѫ����ɫ������������ˡ�\n\n" NOR,
                me, target );

        target->clear_condition();
       me->add("neili", -300);
       me->add("max_neili", -10); 
       return 1;
      
       }

     return 1;
}
