// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// king
// »ðÉñ×Ó
// [1;31mË¼¹ýÖÐ...[2;37;0m
// 2792324
// ÄÐÐÔ
// unarmed
// ¸òó¡ÈýµþÀË





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÇ°ÍÈÌß³ö£¬ºóÍÈ½Å¼âµãµØ£¬Ò»Ê½¡¸¸òó¡³öÀË¡¹£¬¶þÕÆÖ±³ö£¬¹¥Ïò$nµÄÉÏÖÐÏÂÈýÂ·.$N×ÝÉíÒ»Ô¾£¬ÄÚÎü°µÔË.¡¸¸òó¡³ö³¾¡¹¶Ô×¼$nµÄÍ·²¿Î»»º»ºÅÄ³öÒ»ÕÆ.",
"force" :50,
"dodge" :10,
"damage_type": "ðöÉË",
"lvl" : 0,
"skill_name" : "³öÀËÊÔ"
]),
// ZHAOSHI :1

([
"action" :"$RED$ $N·ÉÉíÔ¾Æð,ºóÍÈ¹òµØ,Ò»Ê½¡¸¸òó¡ÆðÀË¡¹Ë«ÊÖÑ¸ÃÍÎÞ±ÈµÄ¹¥Ïò$nµÄ×ó¼ç.$HIW$ $NÍ»È»×ªÉí,Ë«ÊÖÓÖÒ»Ê½¡¸Æ½·çÆðÀË¡¹¶Ô×¼$nµÄË«ÍÈÇáÅÄ¹ýÈ¥.",
"force" :80,
"dodge" :-10,
"damage_type": "ðöÉË",
"lvl" : 12,
"skill_name" : "ÆðÀËÊÔ"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"¸òó¡ÈýµþÀË"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"¸òó¡ÈýµþÀË"+"¡£\n");
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
    level = (int)me->query_skill("sandeilang-unarmed",1);
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
