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
      return notify_fail(HIC"该功能只能施于别人。\n"NOR);
      if(!together(me,target))
      return notify_fail(HIC"这种情况下你无法为"+target->name()+"发功。\n"NOR);


        if( me->is_fighting() )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(YEL"战斗时替别人打通经脉会导致走火入魔！\n"NOR);
               }

        if ((int)me->query_skill("xiake-shengong", 1) < 50)
              {
               if(test_zouhuorumo(me)) return notify_fail("");  
                return notify_fail(YEL"你的侠客神功火候不够,如果强行替人打通经脉会引起走火入魔。\n"NOR);
               }
     if((me->query("jing")*100/me->query("max_jing")) < 70)
      {
     if(test_zouhuorumo(me)) return notify_fail("");
     return notify_fail(YEL"你现在精力不够，替人打通经脉会导致走火入魔。\n"NOR);

       }
     if((me->query("qi")*100/me->query("max_qi")) < 60)
      {
     if(test_zouhuorumo(me)) return notify_fail("");
     return notify_fail(YEL"你现在精力不够，替人打通经脉会导致走火入魔。\n"NOR);

       }
    if((duration=target->query_condition("zouhuorumo"))<1)
        return notify_fail(HIC+target->name()+"并没有走火入魔呀！\n"NOR);
 target->remove_all_enemy();
 target->remove_all_killer();
 target->start_busy(6);
 target->apply_condition("zouhuorumo",0);
message_vision(HIW
      "$N一掌拍在了$n的顶门上，$n顿时安静了下来，$N盘腿坐了下来\n"+
    "，双掌按在$n的背心要穴开始运功帮$n调理全身经脉和真气。\n"NOR,me,target);

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
     tell_object(me,HIR"你受到对方强劲内力的反扑，内息开始紊乱，\n"+
          ".............\n你也走火入魔了。\n.......\n"NOR);
     message_vision(HIW"$N突然浑身打起颤来，看来是内息紊乱走火入魔了。\n",
                 me,me);
     me->set("temp/type",random(4));
     me->apply_condition("zouhuorumo",me->query("neili")/30);
     if(random(2)) target->die();
     target->unconcious();     
     return ; 
       }
    if(test_zouhuorumo(me))
      {
      tell_object(me,HIR"你受到对方强劲内力的反扑，内息开始紊乱，\n"+
          ".............\n你也走火入魔了。\n.......\n"NOR);
     message_vision(HIW"$N突然浑身打起颤来，看来是内息紊乱走火入魔了。\n",
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
     tell_object(me,HIR"你受到对方强劲内力的反扑，内息开始紊乱，\n"+
          ".............\n你也走火入魔了。\n.......\n"NOR);
     message_vision(HIW"$N突然浑身打起颤来，看来是内息紊乱走火入魔了。\n",
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
  message_vision(HIC"$N满头大汗的站了起来，深深的呼了一口气，$n脸色\n"+
     "微红，看来已经好了。\n"NOR,me,target);
  me->set("neili",0);
  me->set("qi",me->query("qi")/2);
  me->set("jing",me->query("jing")/2);
  me->add("max_neili",-me->query("neili")/20);
  me->improve_skill("force",random(target->query("neili")/10)+10);
  target->apply_condition("zouhuorumo",0);
  }

