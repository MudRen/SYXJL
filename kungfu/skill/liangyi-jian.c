// liangyi-jian.c (kunlun) 昆仑派正两仪剑法

#include <ansi.h>
inherit SKILL;

mapping *action = ({ // 12 招
([      "action":"$N一式「顺水推舟」，手中$w指向自己胸口，剑柄斜斜向外，缓缓划向$n的$l",
        "force" : 180,
                  "dodge" : 5,
                  "parry" : 5,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "顺水推舟",
        "damage_type":"刺伤"
]),
([      "action":HIR"$N身形微侧，左手后摆，右手$w一招「横扫千军」，直向$n的腰间挥去"NOR,
        "force" : 230,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 45,
        "lvl" : 10,
        "skill_name" : "横扫千军",
        "damage_type":"刺伤"
]),
([      "action":BLU"$N纵身近前，$w斗然弯弯弹出，剑光爆长，一招「峭壁断云」，猛地刺
向$n的胸口"NOR,
        "force" : 280,
                  "dodge" : 10,
                  "parry" : 15,
        "damage": 55,
        "lvl" : 20,
        "skill_name" : "峭壁断云",
        "damage_type":"刺伤"
]),
([      "action":YEL"$N左手捏个剑决，平推而出，决指上仰，右手剑朝天不动，一招「仙人指路」，
刺向$n"NOR,
        "force" : 360,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 60,
        "lvl" : 31,
        "skill_name" : "仙人指路",
        "damage_type":"刺伤"
]),
([      "action":HIM"$N剑招忽变，使出一招「雨打飞花」，全走斜势，但七八招斜势
中偶尔又挟着一招正势，教人极难捉摸"NOR,
        "force" : 410,
                  "dodge" : 15,
                  "parry" : 20,
        "damage": 50,
        "lvl" : 43,
        "skill_name" : "雨打飞花",
        "damage_type":"刺伤"
]),
([      "action":HIY"$N手中$w剑刃平刺，锋口向着左右，一招「大漠平沙」，刺向$n"NOR,
        "force" : 450,
                  "dodge" : 20,
                  "parry" : 20,
        "damage": 80,
        "lvl" : 52,
        "skill_name" : "大漠平沙",
        "damage_type":"刺伤"
]),
([      "action":"$N一招「木叶萧萧」，横提$w，剑尖斜指向地，由下而上，撩向$n的$l",
        "force" : 420,
                  "dodge" : 25,
                  "parry" : 30,
        "damage": 85,
        "lvl" : 62,
        "skill_name" : "木叶萧萧",
        "damage_type":"刺伤"
]),
([      "action":RED"$N抢前一步，$w微微抖动，剑光点点，一招「江河不竭」，终而复始，
绵绵不绝刺向$n"NOR,
        "force" : 480,
                  "dodge" : 30,
                  "parry" : 30,
        "damage": 95,
        "lvl" : 74,
        "skill_name" : "江河不竭",
        "damage_type":"刺伤"
]),
([      "action":MAG"$N左手剑鞘一举，快逾电光石光，一招「高塔挂云」，用剑鞘套住
$n手中兵器，$w直指$n的咽喉"NOR,
        "force" : 460,
                  "dodge" : 40,
                  "parry" : 40,
        "damage": 100,
        "lvl" : 85,
        "skill_name" : "高塔挂云",
        "damage_type":"刺伤"
]),
([      "action":"$N翻身回剑，剑诀斜引，一招「百丈飞瀑」，剑锋从半空中直泻下来，
罩住$n上方",
        "force" : 540,
                  "dodge" : 35,
                  "parry" : 35,
        "damage": 105,
        "lvl" : 95,
        "skill_name" : "百丈飞瀑",
        "damage_type":"刺伤"
]),
([      "action":HIB"$N一式「雪拥蓝桥」，$N手中剑花团团，一条白练疾风般向卷向$n"NOR,
        "force" : 500,
                  "dodge" : 40,
                  "parry" : 45,
        "damage": 115,
        "lvl" : 107,
        "skill_name" : "雪拥蓝桥",
        "damage_type":"刺伤"
]),
([      "action":HIW"$N腾空而起，突然使出一招「无声无色」，悄无声息地疾向$n的背部刺去"NOR,
        "force" : 550,
                  "dodge" : 50,
                  "parry" : 55,
        "damage": 125,
        "lvl" : 120,
        "skill_name" : "无声无色",
        "damage_type":"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        int na, nl;
        na = (int)me->query_skill("art", 1);
        nl = (int)me->query_skill("liangyi-jian", 1);

        if (me->query("family/master_name") == "何足道" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("琴棋书画当与武功并重，不然你无法领会更高深的昆仑正两仪剑法。\n");
        }

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if (me->query_skill_mapped("force") != "xuantian-wuji")
                return notify_fail("修习两仪剑必须有玄天无极功配合。\n");
        if ((int)me->query_skill("xuantian-wuji", 1) < 20)
                return notify_fail("你的玄天无极功火候太浅。\n");
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
        level   = (int) me->query_skill("liangyi-jian",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        int na, nl;
        int lvl = me->query_skill("liangyi-jian", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        na = (int)me->query_skill("art", 1);
        nl = (int)me->query_skill("liangyi-jian", 1);

        if (me->query("family/master_name") == "何足道" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("琴棋书画当与武功并重，不然你无法领会更高深的昆仑正两仪剑法。\n");
        }

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
         if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练两仪剑法。\n");
         me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liangyi-jian/" + action;
}

