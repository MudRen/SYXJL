#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me)
{
	object weapon, weapon2, target;
        string msg;

	me->clean_up_enemy();
	target = me->select_opponent(); 

	if( !me->is_fighting() )
		return notify_fail("红花十三剑「崩」字决只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够！\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有用兵刃，你用不了「崩」字诀。\n");

	if( (int)me->query_skill("sword") < 50 ||
	    me->query_skill_mapped("sword") != "luohua-jian")
		return notify_fail("你的「红花十三剑」还不到家，无法使用「崩」字决！\n");

	msg = HIY "$N稳住身形，吐气开声，使出红花剑“崩”字决\n" NOR;
	message_vision(msg, me);
	
	if ( random(me->query("str")) > (int)target->query("str")/2 && me->query("combat_exp") > (int)target->query("combat_exp")/4*3 )
//	if ( me->query("str") > (int)target->query("str") )
		{
			msg = HIY"$n只觉得虎口剧痛，手中";
			msg += weapon2->name();
			msg += "顿时把捏不住脱手飞了出去！\n" NOR;
			me->add("neili", -150);
			target->start_busy(2);
			weapon2->move(environment(me));
		}

	else 	{
			me->add("neili",-50);
			msg = HIY"可是$n看出了$N的企图，立刻手上加劲，将
" + weapon2->name() + "奋力向外一挡，\n双方兵刃的碰在一起,“铛”的发出一声巨响\n"NOR;
			me->start_busy(2);
		}

	message_vision(msg, me, target);

	return 1;
}
