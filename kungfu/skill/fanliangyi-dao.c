// fanliangyi-dao.c 反两仪刀法

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「混沌一破」，反身一顿，一刀向$n的$l撩去",
	"force" : 120,
	"dodge" : -10,
	"lvl" : 0,
	"skill_name" : "混沌一破",
	"damage_type" : "割伤"
]),
([      "action" : "$N身形闪动抢达“明夷”，$w一式「太乙生萌」，凌历无俦地对准$n的$l
劈砍下去",
	"force" : 140,
	"dodge" : -10,
	"damage" : 5,
	"lvl" : 20,
	"skill_name" : "太乙生萌",
	"damage_type" : "割伤"
]),
([      "action" : "$N向前跨上一步，稳据“无妄”使出「两仪合德」，挥动$w向$n左右
闪电般连斩两刀",
	"force" : 160,
	"dodge" : -5,
	"damage" : 15,
	"lvl" : 40,
	"skill_name" : "两仪合德",
	"damage_type" : "割伤"
]),
([      "action" : "$N揉身而上至“随”位，$w交左手反劈「日月晦明」，幻起无数刀光狂削，令
$n看不清来势",
	"force" : 180,
	"dodge" : 5,
	"damage" : 25,
	"lvl" : 60,
	"skill_name" : "日月晦明",
	"damage_type" : "割伤"
]),
([      "action" : "$N使出「无色无相」旋身到“归妹”，左掌劲气弥漫直拍而出，右手$w却无声无息挥至
$n的$l",
	"force" : 200,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 80,
	"skill_name" : "无色无相",
	"damage_type" : "割伤"
]),
([      "action" : "$N反踏两仪方位满场游走，一招「万劫不复」连划数弧，$w激起刺骨寒风，将$n裹入
刀气的旋涡中",
	"force" : 250,
	"dodge" : 15,
	"damage" : 35,
	"lvl" : 100,
	"skill_name" : "万劫不复",
	"damage_type" : "割伤"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的「紫霞神功」火候太浅。\n");
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
	level   = (int) me->query_skill("fanliangyi-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练「反两仪刀法」。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fanliangyi-dao/" + action;
}
