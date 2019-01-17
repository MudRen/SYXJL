// lifeheal.c

#include <ansi.h>
#include <cond.h>
#include <spec.h>

string *jingmai=({
  "����",
  "����",
  "����",
  "����",
  "��ά",
  "��ά",
  "����",
  "����",
});

int exert(object me, object target)
{
       if(!target)
        return notify_fail(HIC"��Ҫ��˭��ͨ������\n"NOR);
      if(target==me) 
      return notify_fail(HIC"�ù���ֻ��ʩ�ڱ��ˡ�\n"NOR);
      if(!together(me,target))
      return notify_fail(HIC"������������޷�Ϊ"+target->name()+"������\n"NOR);
        if(me->is_busy())
         return notify_fail("��̫æ�ˡ�\n");

        if( me->is_fighting() || target->is_fighting())
          {
         if(test_zouhuorumo(me)) return notify_fail("");
        return notify_fail("ս�����˹��ᵼ���߻���ħ��\n");
             }
        if(me->query_skill("xiake-shengong",1)<100)
              {
            if(test_zouhuorumo(me)) return notify_fail("");
        return notify_fail("��������񹦻�򲻹���ǿ�������ᵼ���߻���ħ��\n");
                 }
     
        if( (int)me->query("max_neili") < (target->query("max_neili")*2/3) )
              {
            if(test_zouhuorumo(me)) return notify_fail("");    
        return notify_fail("���������Ϊ������ǿ�������ᵼ���߻���ħ��\n");
                 }

        if( (int)me->query("neili") < 1000 )
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
        if(target->query_skill("xiake-shengong",1)%10==0)
          if(target->query("jingmai")<(target->query_skill("xiake-shengong",1)/10))
       {
  message_vision(CYN"$N��ϥ����������˫�ֵ�ס$n�ı��ģ���ʼ��$n����"+
        "������\n"+NOR,me,target);
   me->start_busy(3);
   target->start_busy(4);
  remove_call_out("finished");
  call_out("finished",1,me,target,0);
  return 1;
        } 
 
return notify_fail(HIC+target->name()+"��û����Ҫ��ͨ������ʱ��\n"NOR);
}

void finished(object me,object target,int i)
{
 switch(i)
   {
  case 0:
//  message_vision(CYN"$N��ͷ�Ͻ���ð��������$n����Ҳ��������ˡ�\n",me,target,
  //        ({me,target}));
    tell_room(environment(me),CYN+me->name()+"��ͷ�Ͻ���ð��������"+
         target->name()+"����Ҳ��������ˡ�\n"NOR,me,target);
    tell_object(me,HIC"�㲻�ϵļ�ǿ���������\n"NOR);
    tell_object(target,HIC+me->name()+"����������Խ��Խǿ��\n"NOR);
    break;
 case 1:
//message_vision(CYN"$N��ͷ�ϰ���Խ��ԽŨ���𽥰��˶���Χ��������\n",me,target,
  //        ({me,target}));
 tell_room(environment(me),CYN+me->name()+
           "��ͷ�ϰ���Խ��ԽŨ���𽥰��˶���Χ��������\n"NOR,me,target);
    tell_object(me,HIC"�㰵��һ����������ͣ�Ĵ߶����������\n"NOR);
   tell_object(target,HIC+me->name()+"����������Խ��Խǿ������û����������һ�㡣\n"NOR);
    break;

  case 2:
  message_vision(CYN"$N���١���һ������������ߵ��˼��ޡ�\n"NOR,me);
//message_vision(CYN"ֻ��$Nͷ�ϵ����������۳�һ�ߣ�$n����Ҳ��ɽ���ɫ��\n",me,
//      target,({me,target}));
 tell_room(environment(me),CYN+"ֻ��"+me->name()+
  "ͷ�ϵ����������۳�һ�ߣ�"+target->name()+"����Ҳ��ɽ���ɫ��\n"NOR,me,target);
  tell_object(target,HIC"һ��ǿ�ҵ���������ı��Ĵ�Ѩֱ����������ڣ�Ѹ��"+
          "���������"+jingmai[target->query("jingmai")]+"��\n�����"+
          jingmai[target->query("jingmai")]+"���������Ƶģ���һ�ֱ���ͨ�ĸо���\n"NOR);
    break;
  case 3:
   message_vision("$N���չ���$n����ɫҲ�ָ���������\n",me,target);
   tell_object(target,HIC"����û�����ˬ�����������������µ�ͻ�ơ�\n"NOR);
   tell_object(me,HIC"��о����ۣ�����տյģ��������������ʧ���١�\n"NOR);
   me->receive_damage("qi",target->query("jingmai")*10);
   me->receive_damage("jing",target->query("jingmai")*5);
   me->add("max_neili",-target->query("jingmai")*10);
   me->add("neili",-1000);
   target->add("max_neili",target->query("jingmai")*20);
   target->set("jingmai",target->query("jingmai")+1);
   return ;
     }
 me->start_busy(2);
 target->start_busy(2);
 call_out("finished",2,me,target,i+1);
 }
