// heal.c by rhxlwd 99.02

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
               return notify_fail("ս�����ƾ���������\n");

          if ((int)me->query_skill("beiming-shengong", 1) < 50)
                return notify_fail("��ı�ڤ����Ϊ��������\n");
          if( (int)me->query("jingli") < 50 ) // - (int)me->query("max_jingli") < 50 )
                    return notify_fail("��ľ���������\n");

          if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

          write( HIG "�����������������ʼ��������\n" NOR);
        message("vision",
                  HIG + me->name() + "����һ���������������ö��ˡ�\n" NOR,
                environment(me), me);

          me->receive_curing("jing", 10 + (int)me->query_skill("force")/5 );
          me->add("jingli", -50);
        me->set("jiali", 0);
      me->start_busy(4);

        return 1;
}

