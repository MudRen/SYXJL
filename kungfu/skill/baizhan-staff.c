// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// lks
// 兰特
// 白驼山派第二代弟子
// 2143602
// 男性
// staff
// 百战刀法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N横手反握$w，大喝一声，身子螺旋般地腾空而起，罩向$n全身。",
"force" :650,
"dodge" :50,
"parry" :50,
"damage_type": "挫伤",
"damage": 300,
"lvl" : 0,
"skill_name" : "星火燎原"
]),
// ZHAOSHI :1

([
"action" :"在万众期待中，$w像阳光彩虹般由鞘内拔了出来，随着$N前冲的步法,化为迅雷闪电，\n刮过两人丈许的空间，向严阵以待的$n的$l劈去。",
"force" :680,
"dodge" :80,
"parry" :80,
"damage": 400,
"damage_type": "挫伤",
"lvl" : 12,
"skill_name" : "迅雷闪电"
]),
// ZHAOSHI :2

([
"action" :"$N手中的$w犹如羚羊挂角，去留无游，电光急闪，刀气翻腾,已如惊涛骇浪般的向$n的$l砍去。",
"force" :700,
"dodge" :100,
"parry" :100,
"damage_type": "挫伤",
"damage": 500,
"lvl" : 20,
"skill_name" : "惊涛骇浪"
]),
// ZHAOSHI :3

([
"action" :"$N在气机牵引，彼退我进下，一声长啸，挺刀攻去，森森刀浪，随着冲前的步势，\n漫罩而来，那种骇人的感觉，重若泰山，紧锁$n的灵魂和肉身，使他泛起难以力抗的感觉。",
"force" :730,
"dodge" :150,
"parry" :150,
"damage_type": "挫伤",
"damage": 400,
"lvl" : 30,
"skill_name" : "破碎虚空"
]),
// ZHAOSHI :4

([
"action" :"$N眨几眼的工夫向$n连劈角度刁钻无伦的九刀，滔滔不绝的化成一道道芒光，劈往$n的$l。",
"force" :760,
"dodge" :200,
"parry" :200,
"damage_type": "挫伤",
"damage": 400,
"lvl" : 40,
"skill_name" : "逆转九天"
]),
// ZHAOSHI :5

([
"action" :"$N的$w由肩上弹起冷然道：“太迟了！”，猛地加速，似拙实巧,狂劈$n的薄弱点。",
"force" :1000,
"dodge" :300,
"parry" :300,
"damage": 500,
"damage_type": "挫伤",
"lvl" : 50,
"skill_name" : "似拙实巧"
]),

([
"action":"$N一声不响，往后右侧斜退一步，扭身，$w离地斜挑，劈向$n的力量最弱之处--$l。",
"force":1100,
"dodge":350,
"parry":350,
"damage":600,
"damage_type": "挫伤",
"lvl" : 60,
"skill_name" : "斜风细雨"
]),

([
"action":"$N踏前半步，一声狂喝，举刀斜劈$n的$l，风声呼啸，劲厉刺耳，\n像万马千军撕杀于战场之上。",
"force":1100,
"dodge":350,
"parry":350,
"damage":600,
"damage_type": "挫伤",
"lvl" : 70,
"skill_name" : "万马千军"
]),

([
"action":"$N疾冲往前，连人带着$w往$n撞去，两个人影乍合又分，只见$N把$w回扛肩上，\n眼中露出无限的哀怨。",
"force":1200,
"dodge":400,
"parry":400,
"damage":800,
"damage_type": "挫伤",
"lvl" : 80,
"skill_name" : "黯然消魂"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"百战刀法"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "staff" || usage=="parry" || usage=="blade"; }
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
    level = (int)me->query_skill("baizhan-staff",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
       me->receive_damage("qi", 5);
	return 1;
} //total 34 lines!
