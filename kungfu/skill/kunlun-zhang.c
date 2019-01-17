// kunlun-zhang.c 昆仑掌

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N掌风激荡，双掌错落，来势神妙无方，一招「日入空山」，劈向$n的$l",
	"force" : 120,
	"dodge" : -5,
	"parry" : 5,
	"lvl" : 0,
	"skill_name" : "日入空山",
	"damage_type" : "瘀伤"
]),
([      "action" :BLU "$N双掌骤起，一招「天清云淡」，一掌击向$n面门，另一掌却按向
$n$l"NOR,
	"force" : 150,
	"dodge" : 5,
	"parry" : 10,
	"lvl" : 20,
	"skill_name" : "天清云淡",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N双掌互错，变幻莫测，一招「秋风不尽」，前后左右，瞬息之间向$n
攻出了四四一十六招",
	"force" : 200,
	"dodge" : 15,
	"parry" : 10,
	"lvl" : 38,
	"skill_name" : "秋风不尽",
	"damage_type" : "瘀伤",
]),
([      "action" :HIR "$N一声清啸，呼的一掌，一招「山回路转」，自巧转拙，却是去势奇快，
向$n的$l猛击过去"NOR,
	"force" : 230,
	"dodge" : 10,
	"parry" : 15,
	"lvl" : 55,
	"skill_name" : "山回路转",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N双掌交错，若有若无，一招「天衣无缝」，拍向$n的$l",
	"force" : 260,
	"dodge" : 15,
	"parry" : 15,
	"lvl" : 72,
	"skill_name" : "天衣无缝",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一招「青山断河」，右手一拳击出，左掌紧跟着在右拳上一搭，变成双掌下劈，
击向$n的$l",
	"force" : 300,
	"dodge" : 25,
	"parry" : 10,
	"lvl" : 87,
	"skill_name" : "青山断河",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N双手齐划，跟着双掌齐推，一招「北风卷地」，一股排山倒海的掌力，直扑
$n面门",
	"force" : 350,
	"dodge" : 10,
	"parry" : 25,
	"lvl" : 101,
	"skill_name" : "北风卷地",
	"damage_type" : "瘀伤"
]),
([      "action" :HIW "$N突然滴溜溜的转身，一招「天山雪飘」，掌影飞舞，霎时之间将$n四面八方
都裹住了"NOR,
	"force" : 420,
	"dodge" : 25,
	"parry" : 20,
	"lvl" : 120,
	"skill_name" : "天山雪飘",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练昆仑掌必须空手。\n");
	if (me->query_skill_mapped("force") != "xuantian-wuji")
		return notify_fail("练昆仑掌必须有玄天无极功配合。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 20)
		return notify_fail("你的玄天无极功火候不够，无法练昆仑掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练昆仑掌。\n");
	return 1;
}

string query_skill_name(int level)
{
		  int i;
		  for(i = sizeof(action)-1; i >= 0; i--)
					 if(level >= action[i]["lvl"])
								return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
		  int i, level;
	level   = (int) me->query_skill("kunlun-zhang",1);
		  for(i = sizeof(action); i > 0; i--)
					 if(level > action[i-1]["lvl"])
								return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int lvl = me->query_skill("kunlun-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练昆仑掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"kunlun-zhang/" + action;
}

