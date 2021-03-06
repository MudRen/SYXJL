// fushidu.c 化功大法 之 腐尸毒
// by QingP

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, attackp, defendp;
	object obj;

//	if ( !me->query_skill("huagong-dafa", 1)
//	||    me->query_skill_mapped("poison") != "huagong-dafa" )
//		return notify_fail("你不会或者没激发化功大法，无法施“腐尸毒”。\n");

	if( !target ) target = offensive_target(me);

	if( !target	|| !target->is_character() ||	!me->is_fighting(target) )
		return notify_fail("腐尸毒只能在战斗中使用。\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 45 )
		return notify_fail("你的化功大法不够娴熟，不能施腐尸毒。\n");

	if( (int)me->query_skill("beiming-zhenqi", 1) < 110 )
		return notify_fail("你的北冥真气功力不够，不能施腐尸毒。\n");

	if( (int)me->query("neili",1) < 170 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if ((int)me->query_skill("throwing", 1) < 70)
		return notify_fail("你的基本暗器不够娴熟，不能施腐尸毒。\n");

	if ( !(objectp(obj=present("corpse", environment(me)))
	     || objectp(obj=present("corpse", me))
	     || objectp(obj=present("Skeleton", environment(me)))
	     || objectp(obj=present("Skeleton", me)) ) )
		return notify_fail("你周围没有尸体, 怎么施腐尸毒?\n");

	message_vision( CYN "$N顺手抓起尸体，只见尸体陡然间变得乌肿漆黑, 朝$n径直飞去。\n"NOR, me, target );

	attackp = me->query_skill("huagong-dafa",1) + me->query_skill("beiming-zhenqi",1) + me->query_skill("throwing",1) * 2;
	defendp = target->query_skill("force",1) + target->query_skill("dodge") * 2;

	if( attackp / 4 + random( attackp ) > defendp )
	{
		message_vision( CYN " 只听得嗤嗤声响，跟着各人鼻中闻到一股焦臭，真是令人欲呕。\n"
		+ "结果$p被$P攻了个正着！\n" NOR, me, target );

		damage = me->query_skill("huagong-dafa",1) + (int)me->query_skill("beiming-zhenqi", 1)/2;
		damage = damage - random( target->query_skill("dodge")/2 );

		target->receive_damage("jing", damage/2);
		target->receive_wound("jing", random(damage/2));
		target->receive_damage("qi", 70 + damage );

		me->start_busy(2);
		target->start_busy(1 + random(3));

	}
	else {
		message_vision( HIY "可是$p急忙闪在一旁，躲了开去。\n" NOR, me, target );
		me->start_busy(1);
	}

	if( !target->is_killing(me) ) target->kill_ob(me);

	me->add("neili", -135);
	destruct(obj);

	return 1;
}