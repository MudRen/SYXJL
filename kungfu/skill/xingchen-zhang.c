// xingchen-zhang.c 星辰掌法
// by QingP

#include <ansi.h>

inherit SKILL;

string skill_for_advanced = "huagong-dafa";
string basic_skill_for_advanced = "poison";

mapping *normal_action = ({
([      "action": "$N身形陡然变快，旋转起来扑向$n，双掌盘旋飞舞，着着进迫，拍向$n的$l",
	"dodge": 40,
	"force": 330,
	"poison": 30,
	"damage_type": "瘀伤"
]),
([      "action": "$N冷若御风，迅捷无比欺向$n，双掌连环攻向$n周身七大要穴",
	"dodge": 15,
	"force": 370,
	"poison": 45,
	"damage_type": "瘀伤"
]),
([	"action": "$N身法轻灵飘逸，双掌如一对花间蝴蝶，蹁跹不定，翩翩拍向$n$l",
	"dodge": 27,
	"force": 300,
	"poison": 60,
	"damage_type": "瘀伤"
]),
([	"action": "$N神情闲雅清隽，令人心旷神怡，但见掌影飘飘，招招凶险，攻向$n要害",
	"dodge": 10,
	"force": 375,
	"poison": 75,
	"damage_type": "瘀伤"
]),
});

mapping *advanced_action = ({
([      "action": "$N御风飘浮，足不点地，忽而身形一闪，快如闪电，双掌以「流星陨落」之势击向$n的$l",
        "dodge": 60,
        "force": 510,
	"damage": 22,
        "poison": 70,
	"lvl": 0,
        "damage_type": "瘀伤"
]),
([	"action": "$N身形蹁跹不定，瞬间幻出数个身影，忽又合而为一，一招「离形合影」，趁$n惊魂\n未定之时，漫天掌影已铺天盖地般向$n袭来",
	"dodge": 45,
	"force": 570,
	"damage": 27,
        "poison": 100,
	"lvl": 20,
	"damage_type": "瘀伤"
]),
([      "action": "$N身形倏的一拔，化掌为指，暴喝声中无数指影如「千蜂万针」般戳向$n周身要穴",
        "dodge": 55,
        "force": 640,
	"damage": 22,
        "poison": 170,
	"lvl": 45,
        "damage_type": "瘀伤"
]),
([	"action": "$N眼暴精光，使出「雷动九天」，掌缘激出数道黑气，透射刀芒，但见刀芒开合，\n劲气打出数丈，击向$n的$l",
	"dodge": 40,
	"force": 600,
	"damage": 29,
        "poison": 210,
	"lvl": 70,
	"damage_type": "瘀伤"
]),
([	"action": "$N气闲神逸、潇洒如意地拍出一掌，但见掌影一幻十，十幻百，势呈「星火燎原」罩向\n$n的$l",
	"dodge": 70,
	"force": 700,
	"damage": 24,
        "poison": 200,
	"lvl": 100,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry";
}

int valid_combine(string combo) { return combo=="wugong-zhao"; }

mapping query_action(object me, object weapon)
{
	int i, level;
	
	if ( me->query_skill(skill_for_advanced, 1)
	&&   me->query_skill_mapped(basic_skill_for_advanced) == skill_for_advanced )
	{
		level = (int) me->query_skill(skill_for_advanced, 1);
		for(i = sizeof(advanced_action); i > 0; i--)
			if(level > advanced_action[i-1]["lvl"])
				return advanced_action[NewRandom(i, 5, level/5)];
	}
	else {
/*		if (random(me->query_skill("strike")) > 30
		&& me->query_skill("force") > 40 && me->query("neili") > 70 )
		{
			if (random(1) > 0 && objectp(present("bonfire", environment(me))))
 			{
	 			me->add("neili",-20);
 				 return ([
 				"action": "$N猛地身子急旋，如陀螺般连转了十多个圈，大袖拂动，整个火焰堆\n陡地拔起，便如一座火墙向$n压来",
 				"force": 550,
	 			"damage_type": "瘀伤"]);
 			}
			else
			{
				me->add("neili", -15);
 				return ([
 				"action": "$N神色惨淡，猛然间用力咬破舌尖，一口鲜血向$n喷去",
	 			"force": 400,
 				"damage_type": "瘀伤"]);
 			}
		}*/
		return normal_action[random(sizeof(normal_action))];
	}
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练星辰掌法必须空手。\n");
	if ((int)me->query_skill("beiming-zhenqi", 1) < 10)
		return notify_fail("你的北冥真气火候不够，无法练星辰掌法。\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("你的内力太弱，无法练星辰掌法。\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练星辰掌法必须空手。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太差了，不能练星辰掌法。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练星辰掌法。\n");
	if (me->query_skill("xingchen-zhang", 1) < 50)
		me->receive_damage("qi", 15);
	else
		me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

/*mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if ( me->query_skill(skill_for_advanced, 1)
	&&   me->query_skill_mapped(basic_skill_for_advanced) == skill_for_advanced )
	{
		if( damage_bonus < 100 ) return 0;

		if( random(damage_bonus/2) > victim->query_str() )
		{
			victim->receive_wound("qi", (damage_bonus - 100) / 2 );
			return HIB "但见掌影纷飞，毒雾萦绕，忽闻骨骼格格乱响，竟似心脉尽碎之声！\n" NOR;
		}
	}
	else if( random(me->query_skill("xingchen-zhang")) > 10 )
	{
		victim->apply_condition("xx_poison", random(me->query_skill("xingchen-zhang")/10)
		+ 1 + victim->query_condition("xx_poison"));
	}
}*/

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if ( me->query_skill(skill_for_advanced, 1)
	&&   me->query_skill_mapped(basic_skill_for_advanced) == skill_for_advanced
	&&    random(me->query_skill(skill_for_advanced)) > 10 )
	{
		victim->apply_condition("xx_poison", random(me->query_skill("skill_for_advanced")/7)
		+ 1 + victim->query_condition("xx_poison"));
	}
}

string perform_action_file(string action)
{
	return __DIR__"xingchen-zhang/" + action;
}