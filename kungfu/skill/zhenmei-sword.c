// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tang
// ÎÞÃû
// [1;36mµÚÒ»°ÙÁãÈý´úÎäÁÖÃËÖ÷[2;37;0m
// 2210661
// ÄÐÐÔ
// sword
// ÕñÃ¼½£·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÒ»¸öäìÈ÷µÄÒ»×ªÉíÒ»¸öÏãÆ¨Ïò$n´òÈ¥£¬$nÑÚÃæ¶øÍË£¬¿ÚÍÂÏÊÑª£¬µ¹ÔÚµØÉÏ£¡",
"force" :50,
"dodge" :20,
"damage_type": "´ÌÉË",
"lvl" : 0,
"skill_name" : "ÀË×ÓÒ»»ØÍ·"
]),
// ZHAOSHI :1

([
"action" :"Ö»¼û$NÐÐÈç¹í÷È£¬Õ£ÑÛ¾Íµ½ÁË$nµÄÃæÇ°£¬Éì³öÁË$NµÄÊÖÖ¸ÔÚ$nµÄÍ·ÉÏºÝºÝÒ»ÇÃ£¬$nµÄÍ·¶¥ÂíÉÏÃ°³ö¸ö´ó°ü£¬$NµÃÒâµÄ×÷³öÊ¤ÀûµÄÊÖÊÆ! ¡¸ V ¡¹  Ëµ: ¡¸ ¹þ¹þ¹þ...¡¹",
"force" :80,
"dodge" :10,
"damage_type": "´ÌÉË",
"lvl" : 12,
"skill_name" : "ÀË×Ó¶þ»ØÍ·"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"ÕñÃ¼½£·¨"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("zhenmei-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
