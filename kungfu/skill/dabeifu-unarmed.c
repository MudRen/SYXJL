// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tony
// 照宇
// 逍遥派第四代弟子
// 15500583
// 男性
// unarmed
// 阴阳大悲赋





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N神情悲愤，形鬼魅,一式「无法无天」，双手带起无数金色气劲，向$n的全身罩去",
"force" :50,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "无法无天"
]),
// ZHAOSHI :1

([
"action" :"$N冲天而起，激起漫天风沙，一式「魔神天降」，在空中向$n射出两道紫色气劲.",
"force" :80,
"dodge" :-10,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "魔神天降"
]),
// ZHAOSHI :2

([
"action" :"$N幻化出十八条人影,飞身扑上，一式「魔影憧憧」，分别拿向$n的十八道死穴 .",
"force" :100,
"dodge" :-20,
"damage_type": "瘀伤",
"lvl" : 20,
"skill_name" : "魔影憧憧"
]),
// ZHAOSHI :3

([
"action" :"$N双手一张，怪喝一声，一式「极乐魔界」，登时天昏地暗，无数巨石被气劲带起，迅疾的砸向$n.",
"force" :130,
"dodge" :-30,
"damage_type": "瘀伤",
"lvl" : 30,
"skill_name" : "极乐魔界"
]),
// ZHAOSHI :4

([
"action" :"$N聚起全身功力，吸起无数冤魂，使出最后一式「魂飞魄散」，双手气劲夹带无数冤魂夜鬼向$n前胸拍来。",
"force" :150,
"dodge" :-50,
"damage_type": "瘀伤",
"lvl" : 40,
"skill_name" : "魂飞魄散"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"阴阳大悲赋"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"阴阳大悲赋"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("dabeifu-unarmed",1);
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
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
