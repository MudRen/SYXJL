// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// boor
// 冯默风
// 桃花岛第二代弟子
// 2282408
// 男性
// strike
// 伏龙掌





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"只见$N仰天长啸，使出一招天龙八部,身行猛然旋转，仿佛化做三人，左段誉，右虚竹，中萧峰。段誉欺身向前，一招六剑齐发，剑气直射$n印堂！虚竹腾空而起，手中扬起白茫茫一片，似有生死符射向$n百会大穴！萧峰一生暴喝，须发尽立，一式亢龙有悔直拍$n的胸口！只见$n......",
"force" :50,
"dodge" :10,
"damage_type": "内伤",
"lvl" : 0,
"skill_name" : "天龙八部"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"伏龙掌"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"伏龙掌"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "strike" || usage=="parry"; }
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
    level = (int)me->query_skill("fulong-strike",1);
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
