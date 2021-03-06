// lifeheal.c

#include <ansi.h>
#include <cond.h>
#include <spec.h>

string *jingmai=({
  "冲脉",
  "任脉",
  "督脉",
  "带脉",
  "阴维",
  "阳维",
  "阴跤",
  "阳跤",
});

int exert(object me, object target)
{
       if(!target)
        return notify_fail(HIC"你要替谁打通经脉。\n"NOR);
      if(target==me) 
      return notify_fail(HIC"该功能只能施于别人。\n"NOR);
      if(!together(me,target))
      return notify_fail(HIC"这种情况下你无法为"+target->name()+"发功。\n"NOR);
        if(me->is_busy())
         return notify_fail("你太忙了。\n");

        if( me->is_fighting() || target->is_fighting())
          {
         if(test_zouhuorumo(me)) return notify_fail("");
        return notify_fail("战斗中运功会导致走火入魔！\n");
             }
        if(me->query_skill("xiake-shengong",1)<100)
              {
            if(test_zouhuorumo(me)) return notify_fail("");
        return notify_fail("你的侠客神功火候不够，强自运气会导致走火入魔。\n");
                 }
     
        if( (int)me->query("max_neili") < (target->query("max_neili")*2/3) )
              {
            if(test_zouhuorumo(me)) return notify_fail("");    
        return notify_fail("你的内力修为不够，强自运气会导致走火入魔。\n");
                 }

        if( (int)me->query("neili") < 1000 )
             {
            if(test_zouhuorumo(me)) return notify_fail("");    
                return notify_fail("你的真气不够，强自运气会导致走火入魔。\n");
              }
        if((me->query("eff_jing")*100/me->query("max_jing"))<70)
            {
           if(test_zouhuorumo(me)) return notify_fail("");
           return notify_fail("你的精力不够，可能会走火入魔。\n");
             }

        if((me->query("eff_qi")*100/me->query("max_qi"))<60)
          {
          return notify_fail("你先疗疗自己的伤吧。\n");
            }
        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
              {
             if(test_zouhuorumo(target)) return notify_fail("");    
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");
               }
        if(target->query_skill("xiake-shengong",1)%10==0)
          if(target->query("jingmai")<(target->query_skill("xiake-shengong",1)/10))
       {
  message_vision(CYN"$N盘膝坐了下来，双手低住$n的背心，开始帮$n运气"+
        "冲脉。\n"+NOR,me,target);
   me->start_busy(3);
   target->start_busy(4);
  remove_call_out("finished");
  call_out("finished",1,me,target,0);
  return 1;
        } 
 
return notify_fail(HIC+target->name()+"还没到需要打通经脉的时候。\n"NOR);
}

void finished(object me,object target,int i)
{
 switch(i)
   {
  case 0:
//  message_vision(CYN"$N的头上渐渐冒出白气，$n的脸也渐渐变红了。\n",me,target,
  //        ({me,target}));
    tell_room(environment(me),CYN+me->name()+"的头上渐渐冒出白气，"+
         target->name()+"的脸也渐渐变红了。\n"NOR,me,target);
    tell_object(me,HIC"你不断的加强你的内力。\n"NOR);
    tell_object(target,HIC+me->name()+"传来的内力越来越强。\n"NOR);
    break;
 case 1:
//message_vision(CYN"$N的头上白气越来越浓，逐渐把人都包围了起来。\n",me,target,
  //        ({me,target}));
 tell_room(environment(me),CYN+me->name()+
           "的头上白气越来越浓，逐渐把人都包围了起来。\n"NOR,me,target);
    tell_object(me,HIC"你暗吸一口真气，不停的催动你的内力。\n"NOR);
   tell_object(target,HIC+me->name()+"传来的内力越来越强，你觉得混身有如火烧一般。\n"NOR);
    break;

  case 2:
  message_vision(CYN"$N‘嘿’的一声，把内力提高到了极限。\n"NOR,me);
//message_vision(CYN"只见$N头上的真气逐渐凝聚成一线，$n的脸也红成酱紫色。\n",me,
//      target,({me,target}));
 tell_room(environment(me),CYN+"只见"+me->name()+
  "头上的真气逐渐凝聚成一线，"+target->name()+"的脸也红成酱紫色。\n"NOR,me,target);
  tell_object(target,HIC"一股强烈的真气从你的背心大穴直冲入你的体内，迅速"+
          "的行走你的"+jingmai[target->query("jingmai")]+"，\n你觉得"+
          jingmai[target->query("jingmai")]+"好象被烧着似的，有一种被打通的感觉。\n"NOR);
    break;
  case 3:
   message_vision("$N逐渐收功，$n的脸色也恢复了正常。\n",me,target);
   tell_object(target,HIC"你觉得浑身奇爽，内力好象又有了新的突破。\n"NOR);
   tell_object(me,HIC"你感觉很累，丹田空空的，看来你的内力损失不少。\n"NOR);
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
