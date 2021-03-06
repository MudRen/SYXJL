// ningxue-shenzhua.c 凝血神抓

inherit SKILL;

mapping *action = ({
([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「苍龙探爪」抓向$n的$l",
        "dodge": 300,
        "parry": 500,
        "force": 400,
        "damage": 500,
        "lvl" : 300,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双手居高临下一招「飞鹰拨兔」抓向$n的$l",
        "dodge": 350,
        "parry": 480,
        "force": 450,
        "damage": 600,
        "lvl" : 350,
        "damage_type": "瘀伤"
]),
([      "action": "$N右手一招「黑虎掏心」，迅捷无比地抓向$n的$l",
        "dodge": 500,
        "parry": 500,
        "force": 600,
        "damage": 800,
        "lvl" : 400,
        "damage_type": "瘀伤"
]),
([      "action": "$N双手施出一招「泰山压顶」，隐隐带着风声抓向$n的$l",
        "dodge": 800,
        "parry": 800,
        "force": 800,
        "damage": 1000,
        "lvl" : 500,
        "damage_type": "瘀伤"
]),
([      "action": "$N左手聚成虎爪状，右手一招「凝血神抓」缓缓抓向$n的$l",
        "dodge": -10,
        "parry": 50,
        "force": 800,
        "damage": 600,
        "lvl" : 40,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry" ||  usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练凝血神抓必须空手。\n");
        if ((int)me->query_skill("honghua-shengong", 1) < 20)
                return notify_fail("你的红花神功火候不够，无法练凝血神抓。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练凝血神抓。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练凝血神抓。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"ningxue-shenzhua/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

