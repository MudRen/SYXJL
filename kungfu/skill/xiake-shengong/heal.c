// heal.c

#include <ansi.h>
#include <cond.h>

int exert(object me, object target)
{
        if(me->is_busy())
         return notify_fail("����æ��\n");
        if( me->is_fighting() )
               {
               if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("ս�����˹����ˣ�������\n");
                }

        if ((int)me->query_skill("xiake-shengong", 1) < 30)
               {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("��������񹦻�򲻹�,С���߻���ħ��\n");
                }
        if( (int)me->query("max_neili") < 300 )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("���������Ϊ����С���߻���ħ��\n");
               }
        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
          {
            if(test_zouhuorumo(me)) return notify_fail("");     
            return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
          }
write( HIW "����ϥ��������������������������ȫ��忪�������ľ�����\n" NOR);
        message("vision",
HIW + me->name() + "��ϥ�������˹����ˣ�����һ���һ��ף���һ����³�������Ѫ����ɫ�������ö��ˡ�\n" NOR,
                environment(me), me);
        me->receive_curing("qi", 30 + (int)me->query_skill("force")/5 );
        me->receive_curing("jing",10+(int)me->query_skill("force")/5);
        me->add("neili", -50);
        me->start_busy(1);
        me->receive_damage("qi",10);
        me->set("jiali", 0);

        return 1;
}
