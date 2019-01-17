// yiyang-zhi.c 一阳指功

inherit SKILL;

mapping *action = ({
([	"action" : "$N侧身抬臂，右指划了个半圈，一式「阳关三叠」击向$n的$l",
	"force" : 200,
        "dodge" : -5,
	"lvl" : 0,
	"damage": 60,
	"skill_name" : "阳关三叠",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左掌虚托，一式「鲁阳返日」，右指穿腋疾出，指向$n的胸前",
	"force" : 300,
        "dodge" : -5,
	"lvl" : 30,
	"damage": 80,
	"skill_name" : "鲁阳返日",
        "damage_type" : "刺伤"
]),
([	"action" : "$N俯身斜倚，左手半推，右手一式「阳春白雪」，向$n的$l划过",
	"force" : 350,
        "dodge" : 5,
	"lvl" : 45,
	"damage": 95,
	"skill_name" : "阳春白雪",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双目微睁，一式「阳钩挥天」，双手幻化出千百个指影，拂向$n的$l",
	"force" : 400,
        "dodge" : 5,
	"damage": 110,
	"lvl" : 60,
	"skill_name" : "阳钩挥天",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「烈日骄阳」，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
	"force" : 500,
        "dodge" : 15,
	"damage": 130,
	"lvl" : 80,
	"skill_name" : "烈日骄阳",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌平托胸前，十指叉开，一式「丹凤朝阳」，指向$n的周身大穴",
	"force" : 550,
        "dodge" : 20,
	"damage": 150,
	"lvl" : 100,
	"skill_name" : "丹凤朝阳",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌翻飞，一式「阴阳交错」，指端迸出无数道劲气，射向$n的全身",
	"force" : 600,
        "dodge" : 25,
	"damage": 160,
	"lvl" : 120,
	"skill_name" : "阴阳交错",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「三阳开泰」，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
	"force" : 600,
        "dodge" : 30,
	"damage": 200,
	"lvl" : 140,
	"skill_name" : "三阳开泰",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「一指销魂」，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
	"force" : 550,
        "dodge" : 35,
	"damage": 240,
	"lvl" : 160,
	"skill_name" : "一指销魂",
        "damage_type" : "刺伤"
]),
([	"action" : "$N左掌竖立胸前，一式「一指击天」，右手食指扣住拇指，轻轻对着$n一弹",
	"force" : 650,
        "dodge" : 50,
	"damage": 300,
	"lvl" : 180,
	"skill_name" : "一指击天",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="liumai-shenjian" || combo=="duanjia-jian"; }

int valid_learn(object me)
{       
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
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
		level   = (int) me->query_skill("yiyang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
        write("你按著所学练了一遍一阳指。\n");
        return 1;
}

string perform_action_file(string action)
{
	return "/kungfu/skill/yiyang-zhi/" + action;
}

