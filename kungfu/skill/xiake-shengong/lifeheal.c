// lifeheal.c

#include <ansi.h>
#include <cond.h>
#include <spec.h>

int exert(object me, object target)
{
       if(!target)
        return notify_fail(HIC"��Ҫ��˭���ˡ�\n"NOR);
      if(target==me) 
      return notify_fail(HIC"�ù���ֻ��ʩ�ڱ��ˡ�\n"NOR);
      if(!together(me,target))
      return notify_fail(HIC"������������޷�Ϊ"+target->name()+"������\n"NOR);
        if(me->is_busy())
         return notify_fail("��̫æ�ˡ�\n");
        if( !target )
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˣ�\n");
        if ((int)me->query_skill("xiake-shengong", 1) < 50)
               {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("��������񹦻�򲻹�,С���߻���ħ��\n");
                }


        if( (int)me->query("max_neili") < 300 )
              {
            if(test_zouhuorumo(me)) return notify_fail("");    
        return notify_fail("���������Ϊ������ǿ�������ᵼ���߻���ħ��\n");
                 }

        if( (int)me->query("neili") < 100 )
             {
            if(test_zouhuorumo(me)) return notify_fail("");    
                return notify_fail("�������������ǿ�������ᵼ���߻���ħ��\n");
              }
        if((me->query("eff_jing")*100/me->query("max_jing"))<70)
            {
           if(test_zouhuorumo(me)) return notify_fail("");
           return notify_fail("��ľ������������ܻ��߻���ħ��\n");
             }

        if((me->query("eff_qi")*100/me->query("max_qi"))<60)
          {
          return notify_fail("���������Լ����˰ɡ�\n");
            }
        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
              {
             if(test_zouhuorumo(target)) return notify_fail("");    
                return notify_fail( target->name() +
                        "�Ѿ����˹��أ����ܲ�����������𵴣�\n");
               }

        message_vision(
                HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
                "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
                me, target );

        target->receive_curing("qi", 20 + (int)me->query_skill("force")/3 );
        target->receive_curing("jing",10+(int)me->query_skill("force")/3);   
        target->add("qi", 30 + (int)me->query_skill("force")/3 );
        if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
        
        me->receive_damage("qi",20);
        me->add("neili", -80);
        me->set("jiali", 0);
        me->start_busy(1);
        target->start_busy(1);   
        return 1;
}
