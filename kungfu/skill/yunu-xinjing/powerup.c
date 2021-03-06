// powerup.c 玉女心经加力

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill; 
 
        if((string)me->query("family/family_name") != "古墓派" )
                return notify_fail("你又不是古墓弟子，怎么能用高深的玉女心经? \n");        if( target != me )
                return notify_fail("你只能提升自己的战斗力。\n");
        if( (int)me->query("neili")<200)
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_skill("yunu-xinjing",1) < 80)
                return notify_fail("你的玉女心经还不够精熟。\n");

        skill = me->query_skill("force");

        message_vision(
HIC "$N脸色微微一沉，双掌向外一分，姿势曼妙，如一朵"HIW"白玉兰花"HIC"盛开在
初冬的寒风中！\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的玉女心经运行完毕，将内力收回丹田。\n");
}

