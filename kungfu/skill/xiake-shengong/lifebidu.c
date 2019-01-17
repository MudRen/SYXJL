// heal.c

#include <ansi.h>
#include <cond.h>
#include <spec.h>

string poison;
int duration;

int exert(object me, object target)
{
string *names;
        if(!target)
         return notify_fail(HIC"��Ҫ��˭�ƶ���\n"NOR);
       if(me==target)
       return notify_fail(HIC"��ָ��ֻ��������á�\n"NOR);
       if(!together(me,target))
      return notify_fail(HIC"������������޷�Ϊ"+target->name()+"������\n"NOR);

        if( me->is_fighting() )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(YEL"ս�����ƶ��ᵼ���߻���ħ��\n"NOR);
               }

        if ((int)me->query_skill("xiake-shengong", 1) < 50)
              {
               if(test_zouhuorumo(me)) return notify_fail("");  
                return notify_fail(YEL"��������񹦻�򲻹�,���ǿ���ƶ��������߻���ħ��\n"NOR);
               }
        if((int)me->query("max_neili") < 700)
          return notify_fail(HIC"���������Ϊ������\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
          {
             if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
            }

        if(!zhongdu(target))
         return notify_fail(HIC"��鲻��"+target->name()+"��������ʲô�����޷��ɶ���\n"NOR); 

   message_vision("$Nȫ�������ĵ���˿˿������ָ��Ƴ�������$nȫ����ʮ\n"+
      "��Ѩ��������Ƶ�ס$n����̨Ѩ�����Ƶ�ס$n�ı��Ľ����붨״̬��"+
      "\n.........\n......\n"NOR,me,target);
  tell_object(target,HIC"�����ȫ����̣�ԭ���ж��ĸо�����ʧ��\n"NOR); 

        names=keys(my_cond);
        poison=names[0];
        duration=me->query_condition(poison);
        target->apply_condition(poison,0);
        me->start_busy(5);
        target->start_busy(5);
        remove_call_out("result");
         call_out("result",5,me,target); 
        me->set("jiali", 0);

        return 1;
}


void result(object me,object target)
 {
  me->add("neili",-1000);
  me->set("qi",me->query("qi")/2);
  me->set("jing",me->query("jing")/2);
  target->add("eff_jing",
   (target->query("max_jing")-target->query("eff_jing"))/3);
  message_vision(HIC "$N��ɫ�԰׵�վ�������������·���ʪ͸�ˣ���ǹ���\n"+
   "һ˿��Ѫ��$n���������ڵ���һ����������ɫ�ö��ˡ�\n"NOR,me,target);
  target->disable_player("<��˯����>");
  remove_call_out("revive");
  call_out("revive",5,target); 
 if((duration>10) && (me->query("neili") < 500))
 {
  duration=duration-10;
    }
 else
 duration = 0;
  }

void revive(object me)
{
 me->enable_player();
tell_object(me,HIC"���������˹�����\n"NOR);
if(duration>0)
  {
 tell_object(me,HIC"��о������ڵĶ��ز�û����ȫ���Ƴ����⡣\n"NOR);
 me->apply_condition(poison,duration);
 return ;
   }
  if(sizeof(my_cond)>1)
  tell_object(me,HIC"���������˲�ֹһ�ֶ���\n"NOR);
 else
  tell_object(me,HIC"�����ڵĶ�������ȫ�����Ƴ����ˡ�\n"NOR);

}
