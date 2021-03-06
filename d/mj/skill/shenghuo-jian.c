// shenghuo-jian.c 圣火剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N举剑向天，一招「圣火焚心」，手中$w发出怪异的响声，一剑劈向$n的$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "劈伤"
]),
([      "action" : "$N提剑反转，开口吐声，右手$w使出一式「圣火晴天」直刺$n的$l",
        "force" : 180,
        "dodge" : 15,
        "damage" : 40,
        "lvl" : 9,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「伏虎圣火」，$w自上而下划出一道剑光，平平地向$n的$l挥去",
        "force" : 200,
        "dodge" : 10,
        "damage" : 70,
        "lvl" : 19,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「降龙圣火」，$N和$w化做一道剑气横扫$n的$l",
        "force" : 250,
        "dodge" : 10,
        "damage" : 80,
        "lvl" : 39,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「斐然圣火」，$w轻轻回抽，用剑气磨向$n的$l",
        "force" : 350,
        "dodge" : 5,
        "damage" : 90,
        "lvl" : 59,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「圣火岿然」，剑尖虚指，自剑尖发出一道罡气，撩向$n的$l",
        "force" : 400,
        "dodge" : -5,
        "damage" : 100,
        "lvl" : 79,
        "damage_type" : "刺伤"
]),
([  "action" : "$N双手合十，一招「万物具焚」，用尽内力将$w揉做一团剑气，刺向$n的$l",
        "force" : 600,
        "dodge" : -5,
        "damage" : 180,
        "lvl" : 99,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level   = (int) me->query_skill("shenghuo-jian",1);
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
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力不够练圣火剑法。\n");
        me->receive_damage("qi", 40);
        return 1;
}

