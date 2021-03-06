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
         return notify_fail(HIC"你要替谁逼毒。\n"NOR);
       if(me==target)
       return notify_fail(HIC"该指令只能替别人用。\n"NOR);
       if(!together(me,target))
      return notify_fail(HIC"这种情况下你无法为"+target->name()+"发功。\n"NOR);

        if( me->is_fighting() )
              {
                if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(YEL"战斗中疗毒会导致走火入魔！\n"NOR);
               }

        if ((int)me->query_skill("xiake-shengong", 1) < 50)
              {
               if(test_zouhuorumo(me)) return notify_fail("");  
                return notify_fail(YEL"你的侠客神功火候不够,如果强行疗毒会引起走火入魔。\n"NOR);
               }
        if((int)me->query("max_neili") < 700)
          return notify_fail(HIC"你的内力修为不够。\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
          {
             if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
            }

        if(!zhongdu(target))
         return notify_fail(HIC"你查不出"+target->name()+"到底中了什么毒，无法辽毒。\n"NOR); 

   message_vision("$N全身真气鼓荡，丝丝真气从指尖逼出，急点$n全身三十\n"+
      "大穴，最后右掌抵住$n的灵台穴，左掌抵住$n的背心进如入定状态。"+
      "\n.........\n......\n"NOR,me,target);
  tell_object(target,HIC"你觉得全身滚烫，原先中毒的感觉逐渐消失。\n"NOR); 

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
  message_vision(HIC "$N脸色苍白的站了起来，浑身衣服都湿透了，嘴角挂着\n"+
   "一丝鲜血，$n静静的躺在地上一动不动，脸色好多了。\n"NOR,me,target);
  target->disable_player("<昏睡不醒>");
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
tell_object(me,HIC"你逐渐清醒了过来。\n"NOR);
if(duration>0)
  {
 tell_object(me,HIC"你感觉到体内的毒素并没有完全被逼出体外。\n"NOR);
 me->apply_condition(poison,duration);
 return ;
   }
  if(sizeof(my_cond)>1)
  tell_object(me,HIC"你体内中了不止一种毒。\n"NOR);
 else
  tell_object(me,HIC"你体内的毒素终于全部被逼出来了。\n"NOR);

}
