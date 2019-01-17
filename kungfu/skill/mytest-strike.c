// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// duooo
// ËùÂÞÃÅÍõ
// [1;36mµÚÎåÊ®Ò»´ú·£¶ñÊ¹Õß[2;37;0m
// 2138156
// ÄÐÐÔ
// strike
// ÎÒµÄÕÆ·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÇ°ÍÈÌß³ö£¬ºóÍÈ½Å¼âµãµØ£¬Ò»Ê½¡¸ºá¿Õ³öÊÀ¡¹£¬¶þÕÆÖ±³ö£¬¹¥Ïò$nµÄÉÏÖÐÏÂÈýÂ·",
"force" :50,
"dodge" :10,
"damage_type": "ÄÚÉË",
"lvl" : 0,
"skill_name" : "·¢Éú·´¿¹"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"ÎÒµÄÕÆ·¨"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"ÎÒµÄÕÆ·¨"+"¡£\n");
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
    level = (int)me->query_skill("mytest-strike",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
