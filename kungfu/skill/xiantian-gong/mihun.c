#include <ansi.h>

inherit F_SSERVER;

void free(object target);

int exert(object me, object target)
{
   string msg;
   int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

//  if( !target ) target = offensive_target(me);

   if(me->query_skill("force") < 100 || (int)me->query_skill("xiantian-gong",1) < 100)
     return notify_fail("你还没学会迷魂术。。。\n");

   if( !target
   ||      !target->is_character()
   ||      target->is_corpse()
   ||      target==me)
     return notify_fail("你想迷谁的魂？\n");  

   if(target->query_temp("no_move"))
   return notify_fail(target->query("name")+"已经魂不守舍，呆若木鸡了！\n");  

   if((int)me->query("neili") < 200 )
     return notify_fail("你的内力不够！\n");

   if((int)me->query("jing") < 10 )
     return notify_fail("你无法集中精力！\n");

   me->add("neili", -200);
   me->receive_damage("jing", 10);

   msg = HIC"$N默念口诀，暗运真气，看了$n一眼！\n" NOR;
   success = 1;
   ap = me->query_skill("force");
   ap = ap * ap * ap /12 ;
   ap += (int)me->query("combat_exp");
   dp = target->query("combat_exp");

   ap2 = (int)me->query_per();
   dp2 = (int)target->query_per();

   ap3 = (int)me->query("neili");
   dp3 = (int)target->query("neili");
   if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;


   if(success == 1 ){
     msg +=  HIR "$n两眼发直，竟然忘了自己在战斗之中。\n" NOR;
     target->set_temp("no_move", 1);
   
     howlong = random((me->query_skill("force") -100))+1;
     if(howlong>60) howlong=60;
     call_out("free", howlong, target);
   }       
   else {
     msg +=  HIR "$n瞪了$N一眼，毫不为所动！\n" NOR;   
     me->start_busy(1+random(2));        
           if( living(target) ) target->kill_ob(me);
   } 

   message_vision(msg, me, target);

   return 1;
}

void free(object target)
{
   if (target)
   target->delete_temp("no_move");      
   return;
}
