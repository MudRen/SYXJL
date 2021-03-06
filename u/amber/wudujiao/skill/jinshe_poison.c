#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + BLU"痛苦地呻吟了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, HIW "忽感到一阵刺骨的奇痛，犹如被百蛇撕咬，你所中的百蛇毒发作了！\n" NOR );
      message("vision", MAG+me->name() + "面色发紫，双目发直，嘴角不断的流着毒血。\n" NOR ,
            environment(me), me);
   }
      me->receive_wound("qi",20 + random(40));
      me->receive_wound("jing", 10);
      me->apply_condition("jinshe_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
             me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
             me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

