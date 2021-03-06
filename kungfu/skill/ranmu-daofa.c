// ranmu-daofa.c 燃木刀法

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w横摆，一招「寝食不安」，身行一晃，一刀向$n的$l撩去",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 0,
        "skill_name" : "寝食不安",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「万事随缘」，双腿虚点地，$w一提，平刃挥向$n的$l",
        "force" : 190,
        "dodge" : 0,
        "parry" : 10,
        "damage" : 15,
        "lvl" : 20,
        "skill_name" : "万事随缘",
        "damage_type" : "割伤"
]),
([      "action" : "$N面带微笑，$w指向自己，一招「烈火烧身」，刀锋一卷，迅雷之势拦腰斩向$n",
        "force" : 260,
        "dodge" : -5,         
        "parry" : 10,
        "damage" : 25,
        "lvl" : 30,
        "skill_name" : "烈火烧身",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「点木生火」，$w上带着无比劲气，划了一个大弧，笔直劈向$n的$l",
        "force" : 320,
        "dodge" : 5,
        "damage" : 35,
        "lvl" : 40,
        "skill_name" : "点木生火",
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，一招「张弓望月」，双手持刃拦腰反切，砍向$n的胸口",
        "force" : 380,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 50,
        "skill_name" : "张弓望月",
        "damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，使出一招「烈火腾云」，上劈下撩，左挡右开，齐齐罩向$n",
        "force" : 440,
        "dodge" : 15,
        "damage" : 55,
        "lvl" : 60,
        "skill_name" : "烈火腾云",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「通禅守寂」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
        "force" : 490,
        "dodge" : 5,
        "damage" : 70,
        "lvl" : 70,
        "skill_name" : "通禅守寂",
        "damage_type" : "割伤"
]),
([      "action" : "$N盘身驻地，一招「奔流不息」，挥出一片流光般的刀影，向$n的全身涌去",
        "force" : 550,
        "dodge" : 20,
        "damage" : 90,
        "lvl" :80,
        "skill_name" : "奔流不息",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 80)
                return notify_fail("你的混元一气功火候太浅。\n");
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
        level   = (int) me->query_skill("ranmu-daofa",1);
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
                return notify_fail("你的体力不够练燃木刀法。\n");
        me->receive_damage("qi", 25);
        return 1;
}
