// qiuge-daofa.c 秋歌刀法
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action":"$N使一招「一叶浮萍归大海」，手中$w一摆，身形急进如飞，刀人合一，射向$n的$l！",
	"force" : 120,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "一叶浮萍归大海",
	"damage_type":  "割伤"
]),
([      "action":"$N$w划出道道弧光，一招「人生何处不相逢」，刀刀不离$n的$l！",
	"force" : 140,
	"dodge" : -10,
	"damage": 40,
	"lvl" : 15,
	"skill_name" : "人生何处不相逢",
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w刀光宛如流水，一招「衰草斜阳流曲浦」，斜斜削向$n的$l",
	"force" : 160,
	"dodge" : 5,
	"damage": 70,
	"lvl" : 30,
	"skill_name" : "衰草斜阳流曲浦",
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w刀光激荡，一招「黄云影日暗长堤」，斩向$n！",
	"force" : 180,
	"dodge" : 10,
	"damage": 90,
	"lvl" : 45,
	"skill_name" : "黄云影日暗长堤",
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w狂舞，刀光团团簇簇，一招「红萝花繁知景色」，飘飘荡荡向$n落去",
	"force" : 220,
	"dodge" : 15,
	"damage": 110,
	"lvl" : 60,
	"skill_name" : "红萝花繁知景色",
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w刀气森然，一招「白萍香远任依依」直劈$n的$l",
	"force" : 280,
	"dodge" : 25,
	"damage": 130,
	"lvl" : 75,
	"skill_name" : "白萍香远任依依",
	"damage_type":  "割伤"
]),
([      "action":"$N使一招「缤纷天雨落花红」，手中$w摆动，刀光霍霍斩向$n的$l",
	"force" : 340,
	"dodge" : 15,
	"damage": 150,
	"lvl" : 90,
	"skill_name" : "缤纷天雨落花红",
	"damage_type":  "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{ 
/*
       if( (string)me->query("gender") != "男性" )
                return notify_fail(HIW "秋歌刀法是只有男性才能练的武功。\n"NOR);
*/
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");
	return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n使出一招「风摇山竹寒声动」，手中的$v散出丝丝寒气格开了$N的$w。\n",
	"$n手中$v虚晃数刀，一招「淡烟疏雨间斜阳」，刀影中突然爆出一缕光芒从侧面划向$N之必救。\n",
	"$n身形微顿，手中的$v化作一道弧光，一招「雁点青天字一行」，反削$N的$w。\n",
});

string *unarmed_parry_msg = ({
"$n使出一招「霜凋红叶正晚秋」，手中的$v内力激荡，$N的攻势随波而散。\n",
"$n身形急退，手中$v上下飞舞，一招「雨过天连青壁润」，封住$N的招式。\n",
"$n手中的$v挽出朵朵刀花，一招「金花玉萼影浮沉」，游刃有余。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
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
	level   = (int) me->query_skill("qiuge-daofa",1);
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
		return notify_fail("你的体力不够练秋歌刀法。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"qiuge-daofa/" + action;
}
