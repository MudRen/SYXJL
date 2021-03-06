// liusheng-xinyinliu.c 柳生新阴流
#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "只见$n双手提刀，用力在对方的攻击点上一绞，结果$P被强大的力道逼得不得不收招防守。\n",
        BLU"$n以攻为守，以进为退，不论$P如何攻击，只顾奋力猛砍猛杀，$P只有放弃进攻。\n"NOR,
        HIW"$n手中兵刃向一旁斜撩，硬是将$P的攻击挡了回去。\n"NOR,
        HIM"$n眼见$P一招攻来，不慌不忙的反功向$P的$l，结果$P慌忙招架。\n"NOR,
        HIG"$n不闪不避，结果硬是硬生生的格开了$P的攻势。\n"NOR,
        YEL"$n看着$P一招攻来，本来斜指在下的兵刃突然自上断劈下，$P吃了一惊，连忙回撤。\n"NOR,
        CYN"$n左手将$P的手臂用力一推，$P差点失去重心。\n"NOR,
        MAG"只见$n反手直立兵刃，用尽全力架开了$P的攻击。\n"NOR,
        RED"$n突然刀尖对准$P的来势直刺过去，$P大惊之下，连忙收回攻势，转向防守。\n"NOR,
});

mapping *action = ({
([      "action":"$N一招「一刀两断」，$w横摆前胸斩向$n的$l",
        "force" : 75,
        "dodge" : 0,
        "damage": 70,
        "lvl" : 0,
        "skill_name" : "一刀两断",
        "damage_type":  "劈伤"
]),     
([      "action":"$N使出一招「小诘」，剑柄末端的右手用力一推，剑身直刺$n的$l",
        "force" : 95,
        "dodge" : 0,
        "damage": 90,
        "lvl" : 10,
        "skill_name" : "小诘",
        "damage_type":  "刺伤"
]),     
([      "action":"$N使出一招「大诘」，左右手一起握住剑柄，拉回三寸余，然后猛然前刺$n的$l",
        "force" : 100,
        "dodge" : 10,
        "damage": 90,
        "lvl" : 20,
        "skill_name" : "大诘",
        "damage_type":  "刺伤"
]),     
([      "action":"$N一招"HIY"「月影」"+NOR"，奋力劈下，好似斩月一般劈向$n的$l",
        "force" : 150,
        "dodge" : 10,
        "damage": 100,
        "lvl" : 30,
        "skill_name" : "月影",
        "damage_type":  "劈伤"
]),
([      "action":"$N一招"HIM"「半开半向」"+NOR"，手中的$w自上而下毫无拖泥带水地砍向$n的$l",
        "force" : 190,
        "dodge" : 30,
        "damage": 150,
        "lvl" : 50,
        "skill_name" : "半开半向",
        "damage_type":  "劈伤"
]),
([      "action":"$N右脚踏前，左脚虚踏，一式"+HIB"「长短一味」"NOR"，手中$w割向$n的$l",
        "force" : 220,
        "dodge" : 40,
        "damage": 170,
        "lvl" : 70,
        "skill_name" : "长短一味",
        "damage_type":  "割伤"
]),
([      "action":"$N手拖兵仞跃开一步，突然转身到$n的背后，一式"+MAG"「必胜」"NOR"，$w就朝$n的$l刺去",
        "force" : 270,
        "dodge" : 70,
        "damage" : 190,
        "lvl" : 90,
        "skill_name" : "必胜",
        "damage_type":  "刺伤"
]),
([      "action":"$N纵身跃起，一式"+BLU"「逆风」"NOR"，刀光如轮疾转，霍霍斩向$n的$l",
        "force" : 290,
        "dodge" : 10,
        "damage": 220,
        "lvl" : 100,
        "skill_name" : "逆风",
        "damage_type":  "割伤"
]),
([      "action":"$N身体前倾，一式"+RED"「花车」"NOR"，手中$w舞的好似滴水不进，光芒中一剑刺向$n的$l",
        "force" : 320,
        "dodge" : 10,
        "damage": 250,
        "lvl" : 110,
        "skill_name" : "花车",
        "damage_type":  "刺伤"
]),
([      "action":"$N左右手反握$w，一招"+HIR"「手引」"NOR"，$w自下段而上劈向$n的$l",
        "force" : 330,
        "dodge" : 15,
        "damage": 260,
        "lvl" : 120,
        "skill_name" : "手引",
        "damage_type":  "劈伤"
]),
([      "action":"$N双手紧握$w，一招"+HIM"「村云」"NOR"，对准$n的$l干净利落的直刺将过去",
        "force" : 350,
        "dodge" : 30,
        "damage": 270,
        "lvl" : 130,
        "skill_name" : "村云",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w外转，一招"+HIG"「向上」"NOR"，一手持剑，一手推于$w的刀背，整个身体纵起，$w的锋芒挑向$n的$l",
        "force" : 380,
        "dodge" : 30,
        "damage": 290,
        "lvl" : 150,
        "skill_name" : "向上",
        "damage_type":  "劈伤"
]),
([      "action":"不杀人，我们以不被杀为胜。$N的一招"+HIW"「活人刀」"NOR"，猛然毫无杀气的刺向毫无防备$n的$l",
        "force" : 430,
        "dodge" : 40,
        "damage": 300,
        "lvl" : 170,
        "skill_name" : "活人刀",
        "damage_type":  "刺伤"
]),
([      "action":"$n只见白光闪闪，仿佛眼前全部都是$w的影子，突然$N一招"+BLU"「极意」"NOR"，一道剑光直刺$n的$l",
        "force" : 470,
        "dodge" : 40,
        "damage": 350,
        "lvl" : 190,
        "skill_name" : "极意",
        "damage_type":  "刺伤"
]),
([      "action":HBBLU"使出〖天狗抄〗极意——「神妙剑」，手中"NOR"$w"+HBBLU"居然好似自行带动$N的攻势一般劈向$n的$l"NOR,
        "force" : (int)this_player()->query("str")*20,
        "dodge" : (int)this_player()->query_skill("dodge")/3,
        "damage": (int)this_player()->query_skill("bushidao",1)*4,
        "lvl" : 200,
        "skill_name" : "神妙剑",
        "damage_type":  "割伤"
]),
([      "action":WHT"$N疾退五、六步，突然长啸一声，一招「八崮必胜」，手中的"NOR"$w"+WHT"在地上划出一道白光，夹杂着“刺刺”声向$n的$l直逼过去"NOR,
        "force" : (int)this_player()->query("str")*25,
        "dodge" : (int)this_player()->query_skill("dodge")/2,
        "damage": (int)this_player()->query_skill("bushidao",1)*5,
        "lvl" : 210,
        "skill_name" : "八箇必胜",
        "damage_type":  "割伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
        int na, nl;
        na = (int)me->query_skill("bushidao", 1);
        nl = (int)me->query_skill("liusheng-xinyinliu", 1);

        if (me->query("family/master_name") == "柳生石舟斋" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("武士道精神是所有日本剑道流派的支撑，你能不学好？\n");
        }

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if (me->query_skill_mapped("force") != "jiangui-xinfa")
                return notify_fail("修习柳生新阴流必须有剑鬼心法的配合。\n");
        if ((int)me->query_skill("jiangui-xinfa", 1) < 20)
                return notify_fail("你的剑鬼心法火候太浅。\n");
        if ((int)me->query_skill("bushidao", 1) < 20)
                return notify_fail("你的武士道精神几乎没有。\n");        
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
        level   = (int) me->query_skill("liusheng-xinyinliu",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        int na, nl;
        int lvl = me->query_skill("liusheng-xinyinliu", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        na = (int)me->query_skill("bushidao", 1);
        nl = (int)me->query_skill("liusheng-xinyinliu", 1);

        if (me->query("family/master_name") == "柳生石舟斋" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("武士道精神是所有日本剑道流派的支撑，你能不学好？\n");
        }

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
         if ((int)me->query("qi") < 70)
                return notify_fail("你的体力不够练柳生新阴流。\n");
         me->receive_damage("qi", 40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liusheng-xinyinliu/" + action;
}



