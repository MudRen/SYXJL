// duanjia-jian.c 段家剑法
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「云横秦岭」，手中$w幻成一条暗光斩向$n的$l",
        "force" : 40,
        "dodge" : 100,
        "damage": 60,
        "parry" : 100,
        "lvl" : 20,
        "skill_name" : "云横秦岭",
        "damage_type":  "割伤"
]),
([      "action":"$N跨步上前，使出「飞流直下」，手中$w笔直地向$n的$l刺去",
        "force" : 80,
        "dodge" : 150,
        "parry" : 100,
        "damage": 80,
        "lvl" : 40,
        "skill_name" : "飞流直下",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「雪涌蓝关」，幻起漫天剑影，$w罩向$n全身大穴",
        "force" : 100,
        "dodge" : 140, 
        "parry" : 100,
        "damage" : 130,
        "lvl" : 50,
        "skill_name" : "雪涌蓝关",
        "damage_type":  "刺伤"
]),
([      "action":"$N纵身轻轻跃起，一式「奇兵突起」，剑势突然由慢转快，$w直奔$n的$l而去",
        "force" : 100,
        "dodge" : 160,
        "parry" : 100,
        "damage": 150,
        "lvl" : 70,
        "skill_name" : "奇兵突起",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w向下一低，一式「夜叉探海」，无声无息地对准$n的$l刺出一剑",
        "force" : 120,
        "dodge" : 100,
        "parry" : 100,
        "damage": 150,
        "lvl" : 100,
        "skill_name" : "夜叉探海",
        "damage_type":  "刺伤"
]),
([      "action":"$N双手紧握手中$w，直指天穹，剑芒暴涨，一式「泰山压顶」，对准$n的$l砍去",
        "force" : 150,
        "dodge" : 150, 
        "parry" : 100,        "damage": 170,
        "lvl" : 120,
        "skill_name" : "泰山压顶",
        "damage_type":  "割伤"
]),
([      "action":"$N一式「雨打梨花」，左指虚点，一滴鲜血滴在右手$w上，顺势真力一吐，一缕红光向$n飞去",
        "force" : 170,
        "dodge" : 100, 
        "parry" : 100,        "damage": 200,
        "lvl" : 190,
        "skill_name" : "雨打梨花",
        "damage_type":  "刺伤"
]),
([      "action":"$N突的敞开所有门户，一式「逐鹿中原」，$w左右一荡，直取$n的胸膛",
        "force" : 180,
        "dodge" : 100,
        "parry" : 100,
        "damage": 280,
        "lvl" : 200,
        "skill_name" : "逐鹿中原",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="yiyang-zhi"; }


int valid_learn(object me)
{       object ob;
        if (!objectp(ob = me->query_temp("weapon"))
         || (string)ob->query("skill_type") != "sword")
                return notify_fail("你必须先找一把剑才能习练剑法。\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("kurong-changong", 1) < 50)
                return notify_fail("你的枯荣禅功火候太浅。\n");
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
        level   = (int) me->query_skill("duanjia-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练段家剑法。\n");
        me->receive_damage("qi", 25);
        return 1;
}


string perform_action_file(string action)
{
        return "/kungfu/skill/duanjia-jian/" + action;
}

/*int practice_skill(object me)
{
        object ob;

    if( (int)me->query("qi") < 20
    ||  (int)me->query("neili") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习段家剑法。\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你必须先找一把剑才能习练剑法。\n");

    me->receive_damage("qi", 10);
        me->add("force", -2);
    write("你按著所学练了一遍段家剑法。\n");
        return 1;
}*/

