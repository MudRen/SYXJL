// xianglong-zhang.c

inherit SKILL;

mapping *action = ({
([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l",
        "dodge": -30,
        "parry": 10,
        "force": 1000,
        "damage": 160,
        "lvl" : 140,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",
        "dodge": -15,
        "parry": -20,
        "force": 400,
        "damage": 90,
        "lvl" : 120,
        "damage_type": "瘀伤"
]),
([      "action": "$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l",
        "dodge": -10,
        "parry": -10,
        "force": 200,
        "damage": 100,
        "lvl" : 130,
        "damage_type": "瘀伤"
]),
([      "action": "$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l",
        "dodge": -15,
        "parry": -10,
        "force": 300,
        "damage": 100,
        "lvl" : 30,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l",
        "dodge": -10,
        "parry": 10,
        "force": 900,
        "damage": 90,
        "lvl" : 40,
        "damage_type": "瘀伤"
]),
([      "action": "$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l",
        "dodge": -10,
        "parry": 20,
        "force": 400,
        "damage": 100,
        "lvl" : 10,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",
        "dodge": 0,
        "parry": 10,
        "force": 500,
        "damage": 90,
        "lvl" : 20,
        "damage_type": "瘀伤"
]),
([      "action": "$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n",
        "dodge": -25,
        "parry": -10,
        "force": 600,
        "damage": 150,
        "lvl" : 60,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「或跃在渊」，向$n的$l连拍数掌",
        "dodge": -20,
        "parry": -20,
        "force": 700,
        "damage": 120,
        "lvl" : 60,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l",
        "dodge": -10,
        "parry": 20,
        "force": 800,
        "damage": 160,
        "lvl" : 70,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下",
        "dodge": -20,
        "parry": 30,
        "force": 800,
        "damage": 180,
        "lvl" : 80,
        "damage_type": "瘀伤"
]),
([      "action": "$N双掌立起，使出「时乘六龙」向$n连砍六下",
        "dodge": -20,
        "parry": 20,
        "force": 800,
        "damage": 180,
        "lvl" : 80,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",
        "dodge": -15,
        "parry": 20,
        "force": 800,
        "damage": 200,
        "lvl" : 90,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「损则有孚」，双掌软绵绵地拍向$n的$l",
        "dodge": -25,
        "parry": 10,
        "force": 800,
        "damage": 150,
        "lvl" : 80,
        "damage_type": "瘀伤"
]),
([      "action": "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",
        "dodge": -20,
        "parry": 40,
        "force": 800,
        "damage": 250,
        "lvl" : 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N门户大开，一招「履霜冰至」向$n的$l劈去",
        "dodge": -25,
        "parry": 1,
        "force": 800,
        "damage": 280,
        "lvl" : 110,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「羝羊触蕃」，双掌由下往上击向$n的$l",
        "dodge": -15,
        "parry": 40,
        "force": 800,
        "damage": 300,
        "lvl" : 120,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l",
        "dodge": -10,
        "parry": 40,
        "force": 800,
        "damage": 380,
        "lvl" : 140,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练降龙十八掌必须空手。\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 20)
                return notify_fail("你的混天气功火候不够，无法练降龙十八掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
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
                return notify_fail("你的内力不够练降龙十八掌。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xianglong-zhang/" + action;
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

