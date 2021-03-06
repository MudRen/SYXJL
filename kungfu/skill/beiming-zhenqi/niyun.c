// niyun.c 北冥真气 之 逆运
// by QingP

#include <ansi.h>

int exert(object me, object target)
{
	int meqs, targetqs;
	meqs = me->query_skill("beiming-zhenqi", 1);

        if( !target )
                return notify_fail("你想对谁逆运真气？\n");

        if( me->is_fighting() || target->is_fighting() )
                return notify_fail("战斗中你也想逆运真气？！\n");

        if(target == me)
                return notify_fail("你无法在自己体内逆运真气！\n");

	if( (int)me->query_skill("beiming-zhenqi") < 130 )
		  return notify_fail("你的北冥真气修为不够，无法逆运。\n");

        if( (int)me->query("max_neili") < 200 )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < me->query("max_neili") )
                return notify_fail("你的真气不够。\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 7 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");

        if( (int)target->query("max_neili") > (int)me->query("max_neili") )
                return notify_fail( target->name() +
                        "内力比你还强，你怎么逆运真气？！\n");

	     if (target->query_skill("bibo-shengong",1)
		&& target->query_skill("bibo-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("bibo-shengong");
		target->delete_skill("bibo-shengong");
		}

	else if (target->query_skill("beiming-shengong",1)
		&& target->query_skill("beiming-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("beiming-shengong");
		target->delete_skill("beiming-shengong");
		}

	else if (target->query_skill("bahuang-gong",1)
		&& target->query_skill("bahuang-gong",1)
		< meqs)
		{
		targetqs = target->query_skill("bahuang-gong");
		target->delete_skill("bahuang-gong");
		}

	else if (target->query_skill("hamagong",1)
		&& target->query_skill("hamagong",1)
		< meqs)
		{
		targetqs = target->query_skill("hamagong");
		target->delete_skill("hamagong");
		}

	else if (target->query_skill("beiming-zhenqi",1)
		&& target->query_skill("beiming-zhenqi",1)
		< meqs)
		{
		targetqs = target->query_skill("beiming-zhenqi");
		target->delete_skill("beiming-zhenqi");
		}

	else if (target->query_skill("huntian-qigong",1)
		&& target->query_skill("huntian-qigong",1)
		< meqs)
		{
		targetqs = target->query_skill("huntian-qigong");
		target->delete_skill("huntian-qigong");
		}

	else if (target->query_skill("hunyuan-yiqi",1)
		&& target->query_skill("hunyuan-yiqi",1)
		< meqs)
		{
		targetqs = target->query_skill("hunyuan-yiqi");
		target->delete_skill("hunyuan-yiqi");
		}

	else if (target->query_skill("longxiang",1)
		&& target->query_skill("longxiang",1)
		< meqs)
		{
		targetqs = target->query_skill("longxiang");
		target->delete_skill("longxiang");
		}

	else if (target->query_skill("jiuyang-shengong",1)
		&& target->query_skill("jiuyang-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("jiuyang-shengong");
		target->delete_skill("jiuyang-shengong");
		}

	else if (target->query_skill("taiji-shengong",1)
		&& target->query_skill("taiji-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("taiji-shengong");
		target->delete_skill("taiji-shengong");
		}

	else if (target->query_skill("xiaowuxiang",1)
		&& target->query_skill("xiaowuxiang",1)
		< meqs)
		{
		targetqs = target->query_skill("xiaowuxiang");
		target->delete_skill("xiaowuxiang");
		}

	else if (target->query_skill("yunlong-shengong",1)
		&& target->query_skill("yunlong-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("yunlong-shengong");
		target->delete_skill("yunlong-shengong");
		}

	else if (target->query_skill("zixia-shengong",1)
		&& target->query_skill("zixia-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("zixia-shengong");
		target->delete_skill("zixia-shengong");
		}
	else if ( !target->query_skill("bibo-shengong",1)
	&& !target->query_skill("beiming-shengong",1)
	&& !target->query_skill("bahuang-gong",1)
	&& !target->query_skill("hamagong",1)
	&& !target->query_skill("beiming-zhenqi",1)
	&& !target->query_skill("huntian-qigong",1)
	&& !target->query_skill("hunyuan-yiqi",1)
	&& !target->query_skill("longxiang",1)
	&& !target->query_skill("jiuyang-shengong",1)
	&& !target->query_skill("taiji-shengong",1)
	&& !target->query_skill("xiaowuxiang",1)
	&& !target->query_skill("yunlong-shengong",1)
	&& !target->query_skill("zixia-shengong",1) )
		targetqs = 0;

	else return notify_fail("你的真气受到" + target->name() + "体内真气的抵制，无法逆运。\n");

        message_vision(
                HIY "$N哈哈一笑，突然身形拔起，在半空中一个筋斗，头下脚上的倒落下来，\n"
                + "脑袋顶在$n的头顶，两人天灵盖和天灵盖相接。\n\n"
		NOR, me, target );

	tell_object( target,
		HIG "你突觉顶门上“百会穴”中有细细一缕热气冲入脑来，只觉脑海中愈来愈热，\n"
		+ "霎时间头昏脑胀，脑壳如要炸将开来一般，这热气一路向下流去.......\n"
		+ "过不片时，你再也忍耐不住，昏晕了过去。\n");

	target->set("jiali", 0);
	target->set("max_neili", me->query("max_neili"));
	target->set("neili", me->query("max_neili"));
	target->set_skill("beiming-zhenqi", (meqs - targetqs)*7/10 );

	me->set("max_neili", 0);
	me->set("neili", 0);
	me->set_skill("beiming-zhenqi", (meqs - targetqs)*3/10 );

	me->set("jiali", 0);

	me->start_busy(13);
	
	target->unconcious();

	return 1;
}