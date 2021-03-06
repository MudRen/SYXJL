// jinyu-quan.c 金玉拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N拉开马步，一式「双风贯耳」，双拳直取$n的脑门",
	"force" : 50,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "双风贯耳",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「金光灿烂」，幻起一片拳影, 猛地击向$n的$l",
	"force" : 100,
	"dodge" : 10,
	"lvl" : 10,
	"skill_name" : "金光灿烂",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手一挚，先下手为强，使一招「」，双拳向$n的$l打去",
	"force" : 150,
	"dodge" : 15,
	"lvl" : 20,
	"skill_name" : "",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左掌圈花扬起，屈肘当胸，右手虎口朝上，一招「金玉其外」打向$n的$l",
	"force" : 200,
	"dodge" : 20,
	"lvl" : 30,
	"skill_name" : "金玉其外",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N足下一提，使一招「金玉满堂」，跃上半空，双拳划了个半圈，齐击向$n的$l",
	"force" : 250,
	"dodge" : 25,
	"lvl" : 40,
	"skill_name" : "金玉满堂",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N单拳划弧，一记「点石成金」，掌出如电，一下子捶到$n的手上",
	"force" : 300,
	"dodge" : 0,
	"lvl" : 50,
	"skill_name" : "点石成金",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N右脚拄地，左脚挪后半步，施出「金玉夺命」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
	"force" : 350,
	"dodge" : 35,
	"lvl" : 60,
	"skill_name" : "金玉夺命",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N身形微提，两足交错，一式「金石为开」，抡出七拳，瞬如流星，卷向$n的胸口",
	"force" : 400,
	"dodge" : 40,
	"lvl" : 80,
	"skill_name" : "金石为开",
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qingyan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练「金玉拳」必须空手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练「金玉拳」。\n");
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
	level   = (int) me->query_skill("jinyu-quan");
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练「金玉拳」。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -5);
	return 1;
}

/*string perform_action_file(string action)
{
	return __DIR__"jinyu-quan/" + action;
} */