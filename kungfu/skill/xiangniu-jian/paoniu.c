// paoniu 泡妞绝剑
// 2000.12.1  by bsd

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
int i,j;

if( !target ) target = offensive_target(me);

if( !target || !target->is_character()|| !me->is_fighting(target) )

 return notify_fail("「泡妞绝剑」只能对战斗中的对手使用。\n");
/*
if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你所使用的武器不对\n");
*/
    if (me->query("id") != "bsd" )
        return notify_fail("你不是泡妞帮帮主，不能使用这项绝技！\n");
if ( (int)me->query_int() < 35 )
 return notify_fail("你的先天不足，不能领悟「泡妞绝剑」！n");


if( (int)me->query_skill("xiangniu-jian", 1) < 101 )
 return notify_fail("你的泡妞绝剑剑法不够娴熟，不会使用「泡妞绝剑」。\n");

if( (int)me->query("neili")<500)
 return notify_fail("你现在内力太弱，不能使用「泡妞绝剑」。\n");

if( (time()-(int)me->query_temp("last_perform_time"))<
  me->query_temp("last_perform_busy") )
 return notify_fail("你的内力运转的没有这么快。\n");
me->set_temp("last_perform_time",time());
me->set_temp("last_perform_busy",1);

/* */ if(random(2)==1) {
/* */ i
=20;
  message_vision(HIM+"\n$N"+RED+"纵声长笑数声，使出了曾摧残过无数少女的泡妞绝剑。\n"NOR,me);
}
else {
/* */ i=21;
 message_vision(HIM+"\n$N"+RED+"纵声长笑数声，使出了曾摧残过无数少女的泡妞绝剑。\n"NOR,me);
}

me->start_busy(2);
target->start_busy(2);

me->add("force",-random(200));

/* */ weapon=me->query_temp("weapon");
/* */ for(j=1;j<=i;j++) {
 COMBAT_D->do_attack(me, target, weapon, 1);
}

return 1;
}
