// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// brave
// 勇敢的心
// 杀手楼第四代弟子
// 2000000
// 男性
// unarmed
// 亲亲小粉拳





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N捏住$n的脖子，“咂”地一声狠狠亲了一下，$n脸上立刻印上一 个清楚的嘴印儿。",
"force" :50,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "啃"
]),
// ZHAOSHI :1

([
"action" :"$N一把抱住$n，大声叫道：“大功告成！亲个嘴儿。”",
"force" :80,
"dodge" :-10,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "咬"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"亲亲小粉拳"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"亲亲小粉拳"+"。\n");
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
    level = (int)me->query_skill("kiss-unarmed",1);
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
