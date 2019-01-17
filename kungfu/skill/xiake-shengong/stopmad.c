// heal.c

#include <ansi.h>
#include <cond.h>
#include <spec.h>

string poison;
int duration;

int exert(object me, object target)
{
string *names;
      if(target==me)
      return notify_fail(HIC"�ù���ֻ��ʩ�ڱ��ˡ�\n"NOR);
      if(!together(me,target))
      return notify_fail(HIC"������������޷�Ϊ"+target->name()+"������\n"NOR);


        if( me->is_fighting() )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(YEL"ս��ʱ����˴�ͨ�����ᵼ���߻���ħ��\n"NOR);
               }

        if ((int)me->query_skill("xiake-shengong", 1) < 50)
              {
               if(test_zouhuorumo(me)) return notify_fail("");  
                return notify_fail(YEL"��������񹦻�򲻹�,���ǿ�����˴�ͨ�����������߻���ħ��\n"NOR);
               }
     if((me->query("jing")*100/me->query("max_jing")) < 70)
      {
     if(test_zouhuorumo(me)) return notify_fail("");
     return notify_fail(YEL"�����ھ������������˴�ͨ�����ᵼ���߻���ħ��\n"NOR);

       }
     if((me->query("qi")*100/me->query("max_qi")) < 60)
      {
     if(test_zouhuorumo(me)) return notify_fail("");
     return notify_fail(YEL"�����ھ������������˴�ͨ�����ᵼ���߻���ħ��\n"NOR);

       }
    if((duration=target->query_condition("zouhuorumo"))<1)
        return notify_fail(HIC+target->name()+"��û���߻���ħѽ��\n"NOR);
 target->remove_all_enemy();
 target->remove_all_killer();
 target->start_busy(6);
 target->apply_condition("zouhuorumo",0);
message_vision(HIW
      "$Nһ��������$n�Ķ����ϣ�$n��ʱ������������$N������������\n"+
    "��˫�ư���$n�ı���ҪѨ��ʼ�˹���$n����ȫ������������\n"NOR,me,target);

  me->start_busy(4);
  remove_call_out("result");
  call_out("result",4,me,target);
        return 1;
}


void result(object me,object target)
 {

  if(me->query("max_neili")<target->query("max_neili"))
   {
    if(me->query("neili")<target->query("neili"))
      {
     tell_object(me,HIR"���ܵ��Է�ǿ�������ķ��ˣ���Ϣ��ʼ���ң�\n"+
          ".............\n��Ҳ�߻���ħ�ˡ�\n.......\n"NOR);
     message_vision(HIW"$NͻȻ��������������������Ϣ�����߻���ħ�ˡ�\n",
                 me,me);
     me->set("temp/type",random(4));
     me->apply_condition("zouhuorumo",me->query("neili")/30);
     if(random(2)) target->die();
     target->unconcious();     
     return ; 
       }
    if(test_zouhuorumo(me))
      {
      tell_object(me,HIR"���ܵ��Է�ǿ�������ķ��ˣ���Ϣ��ʼ���ң�\n"+
          ".............\n��Ҳ�߻���ħ�ˡ�\n.......\n"NOR);
     message_vision(HIW"$NͻȻ��������������������Ϣ�����߻���ħ�ˡ�\n",
                 me,me);
     me->set("temp/type",random(4));
     me->apply_condition("zouhuorumo",me->query("neili")/30);
     if(random(2)) target->die();
     target->unconcious();
     return ;
   
       }
  me->set("neili",0);
  me->set("qi",me->query("qi")/2);
  me->set("jing",me->query("jing")/2);
  me->add("max_neili",-me->query("neili")/20);

    target->apply_condition("zouhuorumo",duration+random(duration));
    return ;
     }

 if(me->query("neili")<target->query("neili"))
  {
  if(test_zouhuorumo(me))
   {
     tell_object(me,HIR"���ܵ��Է�ǿ�������ķ��ˣ���Ϣ��ʼ���ң�\n"+
          ".............\n��Ҳ�߻���ħ�ˡ�\n.......\n"NOR);
     message_vision(HIW"$NͻȻ��������������������Ϣ�����߻���ħ�ˡ�\n",
                 me,me);
     me->set("temp/type",random(4));
     me->apply_condition("zouhuorumo",me->query("neili")/30);
     if(random(2)) target->die();
     target->unconcious();
     return ;
    }
   if(random(2)) 
    {
  me->set("neili",0);
  me->set("qi",me->query("qi")/2);
  me->set("jing",me->query("jing")/2);
  me->add("max_neili",-me->query("neili")/20);

    target->apply_condition("zouhuorumo",duration+random(duration));
    return ;
     }
   }
  message_vision(HIC"$N��ͷ�󺹵�վ������������ĺ���һ������$n��ɫ\n"+
     "΢�죬�����Ѿ����ˡ�\n"NOR,me,target);
  me->set("neili",0);
  me->set("qi",me->query("qi")/2);
  me->set("jing",me->query("jing")/2);
  me->add("max_neili",-me->query("neili")/20);
  me->improve_skill("force",random(target->query("neili")/10)+10);
  target->apply_condition("zouhuorumo",0);
  }

