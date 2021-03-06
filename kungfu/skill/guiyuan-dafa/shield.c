//shield.c 神功护体

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( (int)me->query("neili") < 100  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("shield") ) 
                return notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_vision(
        HIW "$N双手平举过顶，怒喝一声，运起归元大法，全身笼罩在劲气之中！\n" NOR, me);

        me->add_temp("apply/armor", skill*2);
        me->set_temp("shield", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->delete_temp("shield");
        tell_object(me, "你的归元大法运行完毕，将内力收回丹田。\n");
}
