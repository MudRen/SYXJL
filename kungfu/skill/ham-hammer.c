// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tony
// 照宇
// 日月神教任教主亲传弟子
// 3441498
// 男性
// hammer
// 震天锤





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :50,
"dodge" :20,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "狂风暴雨"
]),
// ZHAOSHI :1

([
"action" :"$N跃入半空，使一招「山崩地裂」，高举金轮敲向$n的颈部  ！",
"force" :80,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "山崩地裂"
]),
// ZHAOSHI :2

([
"action" :"$N提一口真气，使出「海潮汹涌」，金轮扫向$n的头部  ！",
"force" :100,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 20,
"skill_name" : "海潮汹涌"
]),
// ZHAOSHI :3

([
"action" :"$N使一招「灭顶之灾」，金轮如离弦之箭般直捣$n的头部  ！",
"force" :130,
"dodge" :5,
"damage_type": "瘀伤",
"lvl" : 30,
"skill_name" : "灭顶之灾"
]),
// ZHAOSHI :4

([
"action" :"$N使一招「如来佛祖」，就地一滚，手中自下而上撩向$n的胸口  ！",
"force" :150,
"dodge" :-5,
"damage_type": "瘀伤",
"lvl" : 40,
"skill_name" : "如来佛祖"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "hammer") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"震天锤"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="hammer" || usage=="parry"; }
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
    level = (int)me->query_skill("ham-hammer",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
