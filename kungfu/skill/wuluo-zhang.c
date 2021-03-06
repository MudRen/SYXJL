// wuluo-zhang.c -五罗轻烟掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「一缕轻烟」，右掌直出，软绵绵的向$n的前胸劈去。",
        "force" : 200,
        "dodge" : 50,
        "damage": 110,
        "lvl" : 0,
        "skill_name" : "一缕轻烟",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使出一招「朝霞落日」，飞身跃起，双掌同出，劈向$n的$l",
        "force" : 200,
        "dodge" : 50,
        "damage": 100,
        "lvl" : 8,
        "skill_name" : "朝霞落日",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「情丝万缕」，掌指齐出，幻化无穷，攻向$n的各大要害",
        "force" : 200,
        "dodge" : 50,
        "damage": 110,
        "lvl" : 16,
        "skill_name" : "情丝万缕",
        "damage_type" : "瘀伤"
]),
([      "action" : "只见$N双手缠绕，一式「情意绵绵」缓缓轰向$n。",
        "force" : 200,
        "dodge" : 100,
        "damage": 130,
        "lvl" : 24,
        "skill_name" : "情义绵绵",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「天花乱坠」，四面八方出现无数掌影，一掌突出，击向$n的胸口",
        "force" : 220,
        "dodge" : 50,
        "damage": 140,
        "lvl" : 40,
        "skill_name" : "天花乱坠",
        "damage_type" : "内伤"
]),
([      "action" : "$N突然发力，掌冒轻烟，一式「情深义重」，击向$n的$l",
        "force" : 270,
        "dodge" : 50,
        "damage": 140,
        "lvl" : 48,
        "skill_name" : "情深义重",
        "damage_type" : "内伤"
]),
([      "action" : "$N一式「情投意合」,双掌齐伸，遮天蔽日般地笼罩$n的全身要穴",
        "force" : 330,
        "dodge" : 50,
        "damage": 170,
        "lvl" : 54,
        "skill_name" : "山高林密",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N岳立霆峙，一式「地老天荒」，在一阵暴雷声中，双手同时拍向$n的七道死穴",
        "force" : 400,
        "dodge" : 56,
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "地老天荒",
        "damage_type" : "内伤"
]),
([      "action" : "$N眼神一变，脸色发青,一式「无情无意」，在一丝轻烟围绕下，直轰$n涌泉死穴。",
        "force" : 400,
        "dodge" : 56,
        "damage": 220,
        "lvl" : 0,
        "skill_name" : "无情无意",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练五罗轻烟掌必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练五罗轻烟掌。\n");
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
        level   = (int) me->query_skill("wuluo-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够五罗轻烟掌。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuluo-zhang/" + action;
}
