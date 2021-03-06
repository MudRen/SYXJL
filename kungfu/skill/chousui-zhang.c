// chousui-zhang.c, 抽髓掌

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N催动内力，衣袖挥动，双掌挟着一股腥臭之气拍向$n的$l",
        "dodge": 30,
        "force": 160,
        "lvl" : 0,
        "poison": 80,
        "damage_type": "瘀伤"
]),

([  "action": "$N身形旋转起来, 突然间双掌飞舞着拍向$n的$l",
        "dodge": 30,
        "force": 160,
        "lvl" : 29,
        "poison": 60,
        "damage_type": "瘀伤"
]),

([      "action": "$N厉声大喝，掌力加盛，双掌间化出一个斗大的火球, 疾冲$n的$l",
        "dodge": 10,
        "force": 160,
        "lvl" : 59,
        "poison": 40,
        "damage_type": "瘀伤"
]),

([  "action": "$N露出诡异的笑容，一招阴毒无比的「腐尸毒」抓向$n的$l",
        "dodge": 10,
        "force": 160,
        "lvl" : 99,
        "poison": 80,
        "damage_type": "瘀伤"
]),

([  "action": "$N心念一转，计上心来，一招「连珠腐尸毒」连珠般抓向$n的$l",
        "dodge": -10,
        "force": 200,
        "lvl" : 119,
        "poison": 100,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        if (random(me->query_skill("strike")) > 120 &&
            me->query_skill("force") > 120 &&
            me->query("neili") > 2000 ) {
                me->add("neili", -200);
                return ([
                "action": HIR "$N力咬舌尖，鲜血狂喷, 身子如陀螺般连转了十多个圈子，突然间聚集全身的力量击向$n！"NOR,
                "force": 500,
                "damage_type": "瘀伤"]);
        }

        level   = (int) me->query_skill("chousui-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("空了手才能练抽髓掌。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
        return notify_fail("你还是先练好化功大法吧。\n");
        if ((int)me->query("max_neili") < 100)
        return notify_fail("你内力修行太差, 练不了抽髓掌。\n");
        return 1;
}

int practice_skill(object me)
{
        int lvl = me->query_skill("chousui-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jingli") < 40)
        return notify_fail("你先歇口气再练吧。\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("你没有足够的内力练抽髓掌。\n");

        if ((int)me->query("combat_exp") >= 300000 && (int)me->query("max_neili") >= 2000 && (int)me->query_skill("chousui-zhang", 1) >= 120) {
              me->receive_damage("jingli", 40);
              me->add("neili", -15);
              return 1;}

        if ((int)me->query("combat_exp") >= 200000 && (int)me->query("max_neili") >= 1600 && (int)me->query_skill("chousui-zhang", 1) >= 100 && (int)me->query_skill("chousui-zhang", 1) < 120) {
              me->receive_damage("jingli", 35);
              me->add("neili", -10);
              return 1;}

        if ((int)me->query("combat_exp") >= 100000 && (int)me->query("max_neili") >= 800 && (int)me->query_skill("chousui-zhang", 1) >= 80 && (int)me->query_skill("chousui-zhang", 1) < 100) {
              me->receive_damage("jingli", 30);
              me->add("neili", -10);
              return 1;}

        if ((int)me->query("combat_exp") >= 10000 && (int)me->query("max_neili") >= 400 && (int)me->query_skill("chousui-zhang", 1) >= 30 && (int)me->query_skill("chousui-zhang", 1) < 80) {
              me->receive_damage("jingli", 25);
              me->add("neili", -5);
              return 1;}

        if ((int)me->query("combat_exp") >= 3000 && (int)me->query("max_neili") >= 200 && (int)me->query_skill("chousui-zhang", 1) >= 1 && (int)me->query_skill("chousui-zhang", 1) < 30) {
              me->receive_damage("jingli", 20);
              me->add("neili", -5);
              return 1;}

        return notify_fail("你试着练习抽髓掌，但是并没有任何进步。\n");
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
                //if( random(me->query_skill("huagong-dafa")) > (damage_bonus + foo)/3 )
        if(random(me->query_skill("huagong-dafa")) > 30 &&
            me->query_skill("poison") > 50) {
                //victim->receive_wound("qi", (damage_bonus + foo));
                victim->apply_condition("xx_poison", random(2) + 2 +
                        victim->query_condition("xx_poison"));
        }
}