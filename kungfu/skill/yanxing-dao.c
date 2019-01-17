// yanxing-dao.c ÑãÐÐµ¶
inherit SKILL;
mapping *action = ({
([	"action" : "$NÊ¹³ö¡¸ÈÃ×Ö¾÷¡¹£¬Éí×ÓÒ»²à£¬ÈÃ¹ý$n£¬¸ú×Å»Óµ¶Õ¶Ïò$nµÄ$l",
	"force" : 180,
        "dodge" : -10,
        "parry" : 5,
	"damage": 40,
	"lvl" : 0,
	"skill_name" : "ÈÃ×Ö¾÷",
	"damage_type" : "¸îÉË"
]),
([	"action" : "$NÒ»Ê½¡¸´ò×Ö¾÷¡¹£¬×óÕÆÐéÍÐÓÒÖâ£¬ÊÖÖÐ$wË¢µØÒ»Éù×ÔÉÏ¶øÏÂÏò$nÃÍÅü",
	"force" : 200,
        "dodge" : -10,
        "parry" : 10,
	"damage": 50,
	"lvl" : 10,
	"skill_name" : "´ò×Ö¾÷",
	"damage_type" : "¸îÉË"
]),
([	"action" : "$NÒ»Ê½¡¸¶¥×Ö¾÷¡¹£¬Á½½ÅµãµØ£¬Ë«ÊÖÎÕ$w£¬ÃÍÁ¦Ïò$nµÄ$l´ÌÈ¥ü",
	"force" : 220,
        "dodge" : -5,
        "parry" : 5,
	"damage": 60,
	"lvl" : 20,
	"skill_name" : "¶¥×Ö¾÷",
	"damage_type" : "´ÌÉË"
]),
([	"action" : "$NÊ¹Ò»Ê½¡¸Ó¡×Ö¾÷¡¹£¬½Å²½ºó»¬£¬ÊÖÖÐ$wÂýÂýÊÕ»Ø£¬Í»È»·´ÊÖÒ»µ¶Õ¶Ïò$nµÄ$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 5,
	"damage": 70,
	"lvl" : 30,
	"skill_name" : "Òý×Ö¾÷",
	"damage_type" : "¸îÉË",
]),
([	"action" : "$NÊÖÖÐ$wÌôÆð£¬Ò»Ê½¡¸Ì××Ö¾÷¡¹£¬$w»®³öÎÞÊý¹âÈ¦£¬ÂþÌìµ¶Æø£¬Ì×Ïò$nµÄ$l",
	"force" : 280,
        "dodge" : 10,
        "parry" : 5,
	"damage": 80,
	"lvl" : 40,
	"skill_name" : "Ì××Ö¾÷",
	"damage_type" : "¸îÉË"
]),
([	"action" : "$NÉíÐÎÒ»°«£¬Ë«ÊÖºÏÖ´$w£¬Ò»Ê½¡¸³Á×Ö¾÷¡¹£¬ÊÖÖÐ$wÖ±´ÌÏò$nµÄË«ÑÛ",
	"force" : 320,
        "dodge" : 15,
        "parry" : 15,
	"damage": 90,
	"lvl" : 50,
	"skill_name" : "³Á×Ö¾÷",
	"damage_type" : "´ÌÉË"
]),
([	"action" : "$NÒ»Ê½¡¸Ì½×Ö¾÷¡¹£¬ÊÖÖÐ$wÎ¢²ü£¬ÈçòßòÑµãË®°ã¿ìËÙµãÏò$nµÄ$l",
	"force" : 360,
        "dodge" : 15,
        "parry" : 15,
	"damage": 100,
	"lvl" : 60,
	"skill_name" : "Ì½×Ö¾÷",
	"damage_type" : "´ÌÉË"
]),
([	"action" : "$N¿çÉÏÒ»²½£¬Ë«ÊÖÎÕµ¶£¬Ò»Ê½¡¸±Æ×Ö¾÷¡¹£¬ºáÏ÷Ö±¿³¼¤ÆðÕóÕóµ¶·çÏò$n±ÆÈ¥",
	"force" : 400,
        "dodge" : 20,
        "parry" : 10,
	"damage": 110,
	"lvl" : 70,
	"skill_name" : "±Æ×Ö¾÷",
	"damage_type" : "¸îÉË"
]),
([	"action" : "$NÒ»Ê½¡¸²Ø×Ö¾÷¡¹£¬²Øµ¶Éíºó£¬ÃÍÒ»ÐýÉí£¬Ë¤³öÒ»µÀµ¶¹â£¬»®Ïò$nµÄ$l",
	"force" : 450,
        "dodge" : 10,
        "parry" : 20,
	"damage": 120,
	"lvl" : 80,
	"skill_name" : "²Ø×Ö¾÷",
	"damage_type" : "¸îÉË"
]),
([	"action" : "$NÊ¹³öÒ»Ê½¡¸´í×Ö¾÷¡¹£¬½«ÊÖÖÐ$wÏò¾øÎÞ¿ÉÄÜµÄ·½Ïò´ÌÈ¥£¬µ¶¼âÒ»×ª£¬È´Õ¶Ïò$nµÄ$l",
	"force" : 500,
        "dodge" : 5,
        "parry" : 25,
	"damage": 130,
	"lvl" : 90,
	"skill_name" : "´í×Ö¾÷",
	"damage_type" : "¸îÉË"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="yanxing-dao";}
int valid_learn(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("yanxing-dao",1) >99 )
                return notify_fail("ÓÉÓÚÄã²»ÊÇ·ðÃÅÖÐÈË£¬ÐÄÓÐË×Äî£¬²»ÄÜÁì»á·ðÃÅµÄ¸ßÉîÎä¹¦¡£\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("ÄãµÄÁÙ¼ÃÊ®¶þ×¯»ðºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("jinding-mianzhang",1) < 20)
                return notify_fail("ÄãµÄ½ð¶¥ÃàÕÆ»ðºòÌ«Ç³¡£\n");
	return 1;
}
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
	level   = (int) me->query_skill("yanxing-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
        if (me->query("class")!="bonze" && (int)me->query_skill("yanxing-dao",1) >99 )
                return notify_fail("ÓÉÓÚÄã²»ÊÇ·ðÃÅÖÐÈË£¬ÐÄÓÐË×Äî£¬²»ÄÜÁì»á·ðÃÅµÄ¸ßÉîÎä¹¦¡£\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·ÑãÐÐµ¶¡£\n");
	me->receive_damage("qi", 35);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"yanxing-dao/" + action;
}

