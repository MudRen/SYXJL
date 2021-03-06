// 回风拂柳剑

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「清风袭月」，剑锋平指，剑势如风，一股剑气直接冲向$n，气势如宏地猛攻$n的$l",
        "force" : 160,
        "dodge" : 20,
        "parry" : 5,
        "damage" : 25,              
        "skill_name" : "清风袭月",
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「飘雪穿云」，$w的剑风好似一片雪花，直逼$n的$l",
        "force" : 220,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 30,                                                
        "skill_name" : "飘雪穿云",
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w斜指苍天，一式「千峰竞秀」，化出无数个剑尖，好似万道光辉笼罩$N，裹向$n的$l",
        "force" : 250,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 40,                              
        "skill_name" : "千峰竞秀",
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「万流归宗」，$w自上而下缓缓划出一个大弧，这一招看似缓慢，但突然从中向$n的$l刺出",
        "force" : 300,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 50,              
        "skill_name" : "万流归宗",
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N回身拧腰，一式「乌龙搅柱」，$w随身平划，看似无奇，实际上蕴藏绝顶厉害的招数，刺向$n的$l",
        "force" : 330,
        "parry" : 5,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 40,                           
        "skill_name" : "乌龙搅柱",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「大雁啼沙」，全身贴地平飞，身剑合一，霎时间奔向$n，好似闪电般地刺向$n的$l！",
        "force" : 380,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 70,              
        "skill_name" : "大雁啼沙",
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N施出「进退龙游」，$w脱手飞出，如游龙般翱翔青宇，破空之声乍响，射向$n的$l！",
        "force" : 440,
        "dodge" : 20,
        "parry" : 15,
        "damage" : 85,              
        "skill_name" : "进退龙游",
        "lvl" : 65,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长啸一声，一式「天地鹤翔」，腾空飞起，全身迸出无数道雪亮剑芒，照耀天际！使得$n无可适从",
        "force" : 500,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 90,                        
        "skill_name" : "天地鹤翔",
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("你的临济十二庄火候太浅。\n");
        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("你的基本招架火候太浅。\n");
        return 1;
}               
/*
string *hit = ({
"$N一式「清风袭月」，剑锋平指，剑势如风，一股剑气直接冲向$n，气势如宏地猛攻$n的$l",
"$N向前跃上一步，左手剑诀，右手$w使出一式「飘雪穿云」，$w的剑风好似一片雪花，直逼$n的$l",
"N手中$w斜指苍天，一式「千峰竞秀」，化出无数个剑尖，好似万道光辉笼罩$N，裹向$n的$l",
"$N一式「万流归宗」，$w自上而下缓缓划出一个大弧，这一招看似缓慢，但突然从中向$n的$l刺出",
"$N回身拧腰，一式「乌龙搅柱」，$w随身平划，看似无奇，实际上蕴藏绝顶厉害的招数，刺向$n的$l",
"$N一式「大雁啼沙」，全身贴地平飞，身剑合一，霎时间奔向$n，好似闪电般地刺向$n的$l！",
"$N施出「进退龙游」，$w脱手飞出，如游龙般翱翔青宇，破空之声乍响，射向$n的$l！",      
"$N长啸一声，一式「天地鹤翔」，腾空飞起，全身迸出无数道雪亮剑芒，照耀天际！使得$n无可适从",
});             
                       
private string *limb = ({
                "头部", "颈部", "胸口", "后心", "左肩", "右肩", "左臂",
                "右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿",
                "左脚", "右脚", "左耳", "右耳", "左脸", "右脸", "裆部",
});*/
string query_skill_name(int level)
{
    int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        level   = (int) me->query_skill("huifeng-jian",1);
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
        if ((int)me->query("qi") < 20)
                return notify_fail("你的体力不够练回风拂柳剑。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练回风拂柳剑。\n");
        me->receive_damage("neili",5);
        me->receive_damage("qi", 20);   
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wa, wb;
        string msg, type1, hit;
        int i, j, p, skill, neili;
        wa = me->query_temp("weapon");
        wb = ob->query_temp("weapon");
        skill = (int)me->query_skill("huifeng-jian", 1);
        neili = (int)me->query("neili");
        type1 = wa->query("skill_type");
     if( type1 == "sword" && wa && skill > ((int)ob->query_skill("parry", 1)/2)
         && (int)me->query("combat_exp") > (int)ob->query("combat_exp")/10
         && me->query_skill_mapped("parry") == "huifeng-jian"
         && me->query_skill_mapped("sword") == "huifeng-jian"
         && me->query_skill_mapped("force") == "linji-zhuang"
         && (int)me->query_skill("linji-zhuang", 1) > 50
         && neili > 300 && skill > 50 && living(me)
         && (int)me->query("qi") > 500
         && userp(me))
         {
                if(random(2) >= 1)
                {
                i = random(sizeof(action));// if(i=0) i=2;
                msg = "$N不顾$n的进攻，身影轻盈一闪，贴身反击。\n";
                msg += "就在$n发招之时，"+action[i]["action"]+"！\n";
                msg += "$n没有料到$N的招数居然后发先至，匆忙之间，手足无措！\n";
                ob->receive_damage("qi", damage*3/2);
                p = ob->query("qi")*100/ob->query("max_qi");
                msg += damage_msg(damage*3/2, "刺伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                j = -(damage*3);                
                }
                else{                                                
                 msg = "就在$n发招之时，"+action[i]["action"]+"！\n";
                 msg += "$n大吃一惊，但是$p经验老道，见$P攻了过来，紧接着反身又发一招。\n";
                 j = -damage/4; 
               }           

         message_vision(msg, me, ob);
         return j;
         }
}
