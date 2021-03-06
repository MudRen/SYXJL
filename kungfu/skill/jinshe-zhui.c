#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action" : RED"$N一招「灵蛇出洞」，手中"NOR"$w"RED"急射而出，向$n的$l打去"NOR,
        "force" : 200,
        "dodge" : 0,
//        "parry" : -5,
        "damage" : 30,
        "lvl" : 0,     
        "skill_name" : "灵蛇出洞",
        "damage_type" : "刺伤",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIW"$N一招「雪地飞蛇」，越过$n的身后，"NOR"$w"HIW"悄无声息打向$n的$l"NOR,
        "force" : 220,
        "dodge" : 20,
//        "parry" : 0,
        "damage" : 40,
        "lvl" : 15,     
        "skill_name" : "雪地飞蛇",
        "damage_type" : "刺伤",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : WHT"$N斜身进步，一招「杯弓蛇影」，手中数枚"NOR"$w"WHT",笔直飞向$n的$l"NOR,
        "force" : 240,
        "dodge" : 40,
//        "parry" : 5,
        "damage" : 50,
        "lvl" : 30,     
        "skill_name" : "杯弓蛇影",
        "damage_type" : "刺伤",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIC"$N一招「灵蛇闪电」，"NOR"$w"HIC"撒手飞出，竟以不可思议的角度，打向$n的$l"NOR,
        "force" : 270,
        "dodge" : 60,
//        "parry" : 10,
        "damage" : 60,
        "lvl" : 50,     
        "skill_name" : "灵蛇闪电",
        "damage_type" : "",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIG"$N一招「金蛇戏水」，手中"NOR"$w"HIG"犹如无数水珠劈头盖脸打向$n的$l"NOR,
        "force" : 300,
        "dodge" : 80,
//        "parry" : 15,
        "damage" : 70,
        "lvl" : 70,     
        "skill_name" : "金蛇戏水",
        "damage_type" : "刺伤",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIR"$N，向前急越一步,一招「金蛇吐信」，手中"NOR"$w"HIR"由下而上以迅雷不及掩耳之式飞向$n的$l"NOR,
        "force" : 330,
        "dodge" : 100,
//        "parry" : 15,
        "damage" : 90,
        "lvl" : 90,     
        "skill_name" : "金蛇吐信",
        "damage_type" : "刺伤",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIY"$N一招「金蛇游身」，"NOR"$w"HIY"闪烁不定，时快时慢，变幻万千的打向$n的$l"NOR,
        "force" : 370,
        "dodge" : 120,
//        "parry" : 15,
        "damage" : 110,
        "lvl" : 110,     
        "skill_name" : "金蛇游身",
        "damage_type" : "刺伤",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action" : HIM"$N腾空跃起，一招「群蛇乱舞」，数枚"NOR"$w"HIM"脱手而出，一枚接一枚，化着万条金蛇向$n的$l飞去"NOR,        
        "force" : 450,
        "dodge" : 130,
//        "parry" : 20,
        "damage" : 130,
        "lvl" : 140,     
        "skill_name" : "群蛇乱舞",
        "damage_type" : "刺伤",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
        ([      "skill_name":         "千变万化",
                "action":HIB"$N双手一晃，一招「千变万化」，手中的"NOR"$w"HIB"幻出万道金光，
如一条金龙般飞向$n的$l"NOR,
                "dodge":        160,
                "force":        650,
//                "parry" :       25,
                "damage":       160,
                "lvl" : 170,                
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
       ([      "skill_name":         "奇诡莫测",
                "action":MAG"$N右手一抖，一道金光冒出，只一刹那间，左手"NOR"$w"MAG"迅雷般越
过右手的"NOR"$w"MAG"，正是一招「奇诡莫测」，抢先飞向$n的$l"NOR,                
                "dodge":        200,
                "force":        800,
//                "parry" :       30,
                "damage":       200,
                "lvl" : 200,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，没有办法练金蛇锥法。\n");
        if ((int)me->query_skill("throwing", 1) < 50)
                return notify_fail("你的基本暗器都没练到家就象学这么高深的功夫!!!\n");      
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练金蛇锥法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level   = (int) me->query_skill("jinshe-zhui",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 40)
                 return notify_fail("你的气不够，没有办法练习金蛇锥法。\n");
        if( (int)me->query("neili") < 40)
        return notify_fail("你的内力不够，没有办法练习金蛇锥法。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        write("你按著所学练了一遍金蛇锥法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhui/" + action;
}
