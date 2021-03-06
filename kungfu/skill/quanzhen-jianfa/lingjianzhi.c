#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招"HIY"「灵剑指」"NOR"？\n");

        if(!me->is_fighting())
                return notify_fail(""HIY"「灵剑指」"NOR"只能在战斗中使用！\n");

        if((int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够！\n");

/*
        if((int)me->query("family/family_name")!="全真教")
                return notify_fail("你的不是全真弟子，用这招也许会引起一场门派之争！\n");
*/

        if((int)me->query("qi") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("quanzhen-jianfa", 1) < 200)
                return notify_fail("你的全真剑法级别还不够，使用这一招会有困难！\n");

        weapon=me->query_temp("weapon");
   me->delete("env/brief_message");
   message_vision(HIC"\n$N手中剑抖出无数剑花，使出了「灵剑指」。\n"NOR, me);

   me->set("quanzhen", 7);
   message_vision(HIR"\n剑无双。\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->set("quanzhen", 9);
   message_vision(HIY"\n指无视。\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

   me->set("quanzhen", 8);
   message_vision(HIB"\n剑无情。\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->set("quanzhen", 9);
   message_vision(YEL"\n指无灵。\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->set("quanzhen", 6);
   message_vision(MAG"\n剑无心。\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   message_vision(HIM"\n$N长嘘一声，缓缓收招。\n"NOR, me, weapon);

   me->delete("quanzhen");

   me->receive_damage("qi", 100);
   me->add("neili", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(3);
   return 1;
}
