// heal.c

#include <ansi.h>
#include <cond.h>

string poison;
int duration;

int exert(object me, object target)
{
string *names;
        if( me->is_fighting() )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(YEL"ս�����ƶ��ᵼ���߻���ħ��\n"NOR);
               }

        if ((int)me->query_skill("xiake-shengong", 1) < 30)
              {
               if(test_zouhuorumo(me)) return notify_fail("");  
                return notify_fail(YEL"��������񹦻�򲻹�,���ǿ���ƶ��������߻���ħ��\n"NOR);
               }
        if((int)me->query("max_neili") < 500)
          return notify_fail(HIC"���������Ϊ������\n");
        if( (int)me->query("neili") < 600 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
          {
             if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
            }

        if(!zhongdu(me))
         return notify_fail(HIC"��鲻���㵽������ʲô�����޷��ɶ���\n"NOR); 

   write( HIW "����������ס�˵��Ȼ���������������������ȫ��\n" NOR);
   write( HIW "�Ѷ��𽥱���˫�֡�\n......\n"NOR);
   
        message("vision",
HIW + me->name() + "����ɫ����������ת�ף�����ð������ĺ��飬\n" NOR,
                environment(me), me);
        message("vision",
HIW + me->name() + "��������ָ�ϲ�ʱ���º�ɫ�ķ����ȳ�ζ��Һ�塣\n" NOR,
                environment(me), me);

        names=keys(my_cond);
        poison=names[0];
        duration=me->query_condition(poison);
        me->apply_condition(poison,0);
        me->start_busy(5);
        remove_call_out("result");
         call_out("result",5,me); 
        me->set("jiali", 0);

        return 1;
}


void result(object me)
 {
  me->add("neili",-600);
  me->set("qi",me->query("qi")/2);
  me->set("jing",me->query("jing")/2);
  message_vision(HIC "$N��ɫ�԰׵�վ�������������·���ʪ͸�ˣ���ǹ���\n"+
   "һ˿��Ѫ���ŵ�������һ̲�ֺ������ŵ�Һ�塣\n"NOR,me);
  if((duration > 10) && (me->query("neili") < 600))
   {
    tell_object(me,HIC"�������ö���û����ȫ�������\n"NOR);
    me->apply_condition(poison,duration-10); 
    return ;
    }
 if(sizeof(my_cond)>1)
  tell_object(me,HIC"���������˲�ֹһ�ֶ���\n"NOR);
 else
  tell_object(me,HIC"�����ڵĶ�������ȫ�����Ƴ����ˡ�\n"NOR);
  }
