// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// zqsh
// ÇïË®º®
// [1;36mµÚÒ»°Ù¶þÊ®Æß´úÎäÁÖÃËÖ÷[2;37;0m
// 3134570
// ÄÐÐÔ
// sword
// º®Ë®½£·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÏò×óºá¿çÒ»²½£¬ÉíÌåÎ¢Ç°Çã£¬Ò»Ê½¡¸ÈçÇïÖ®Ë®¡¹£¬µãµãº®ÐÇÈöÏò$n£¬$n¶Ù¸Ð¸Ðº®Æø±ÆÈË£¬²»ÓÉÁ¬´ò¾Å¾Å°ËÊ®Ò»¸öÅçÌç¡£",
"force" :50,
"dodge" :20,
"damage_type": "´ÌÉË",
"lvl" : 0,
"skill_name" : "ÈçÇïÖ®Ë®"
]),
// ZHAOSHI :1

([
"action" :"$NÍ»È»Ïòºó¼±ÍË£¬Çá»ÓÊÖÖÐ½££¬Ò»Ê½¡¸ÈçË®Ö®º®¡¹£¬$n¶Ù¾õÈç×¹±ù¿ß£¬»¹ºÃ$NÍËµÄ¿ì£¬²»È»£¬ºÙºÙ£¬Á½¸ö¡£¡£",
"force" :80,
"dodge" :10,
"damage_type": "´ÌÉË",
"lvl" : 12,
"skill_name" : "ÈçË®Ö®º®"
]),
// ZHAOSHI :2

([
"action" :"$NÒ»Ê½¡¸ÂúÌì»¨Óê¡¹£¬Ô¾ÆðÕÉÓà£¬ÊÖÖÐ½£Á¬Á¬»Ó³ö£¬»¯³öÎÞÊý±ù»¨£¬¼±Éä$n",
"force" :100,
"dodge" :10,
"damage_type": "´ÌÉË",
"lvl" : 20,
"skill_name" : "ÂúÌì»¨Óê"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"º®Ë®½£·¨"+"¡£\n");
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
    level = (int)me->query_skill("hanshui-sword",1);
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
