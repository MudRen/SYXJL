// powerup.c
// bye jfeng
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) return notify_fail("你只能用慕容心法提升自己的战斗力。\n");
    if( (int)me->query("neili") < 500)
        return notify_fail("你的真气不够!");
    if( (int)me->query("max_neili") < 400)
        return notify_fail("你的内力修为不够!");
    if( (int)me->query_temp("powerup") ) return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("murong-xinfa",1);
    if (skill<100) return notify_fail("你的慕容心法还不够娴熟。\n");
    me->add("neili", -150);
    me->receive_damage("qi", 0);
    message_vision(
        MAG "$N长吸一口起，运起慕容心法已将全身潜力尽数提起！\n" NOR, me);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill/3);
    me->set_temp("powerup", 1);
    me->add("bellicosity",skill);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/2);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
   if (!me) return;
   if ( (int)me->query_temp("powerup") ) {
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, "你的慕容心法运行结束，提升战斗力完毕。\n");}
}
int clean_up()
{
    return 1;
}
void reset()
{
}
