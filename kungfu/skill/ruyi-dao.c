// ruyi-dao.c »Á“‚µ∂µ  by rhxlwd 99.02
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([     "action" : HIM "$N ÷÷–$w"+HIM"–±÷∏£¨“ª’–°∏À´ÀﬁÀ´∑…°π£¨∑¥◊™$w£¨“‘µ∂±≥œÚ$nµƒ$l«√»•"NOR,
	"force" : 120,
	"dodge" : -10,
	"damage" : 10,
	"lvl" : 0,
	"skill_name" : "À´ÀﬁÀ´∑…",
	"damage_type" : "∏Ó…À"
]),
([      "action" : HIG "“ª Ω°∏ÀÊ–ƒÀ˘”˚°π£¨$N◊Û ÷≥÷µ∂÷¯÷¯Ω¯π•£¨›Îµÿ¿Ô$w"+HIG"º±–˝£¨ª∫ª∫±∆œÚ
$nµƒ$l"NOR,
	"force" : 130,
	"dodge" : -10,
	"damage" : 20,
	"lvl" : 8,
	"skill_name" : "ÀÊ–ƒÀ˘”˚",
	"damage_type" : "∏Ó…À"
]),
  ([      "action" : HIC "$NΩ”◊≈ π≥ˆ°∏–ƒ”–¡Èœ¨°π£¨∂∏»ªº‰∑Á…˘Ï™»ª£¨”“ ÷≥÷$w"+HIC"£¨“ªµ∂◊‘··œÆµΩ£¨∏˙÷¯
”÷ «“ªµ∂£¨¿π—¸’∂œÚ$n"NOR,
	"force" : 140,
	"dodge" : -5,
	"damage" : 30,
	"lvl" : 16,
	"skill_name" : "–ƒ”–¡Èœ¨",
	"damage_type" : "∏Ó…À"
]),
([      "action" : MAG "$N“ª’–°∏“‚¬“«È√‘°π£¨$w"+MAG"»Á”∞ÀÊ–Œµƒ‘Ÿ∑¥ ÷“ªµ∂£¨± ÷±ø≥œÚ$nµƒ$l"NOR,
	"force" : 160,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 24,
	"skill_name" : "“‚¬“«È√‘",
	"damage_type" : "∏Ó…À"
]),
([      "action" : YEL "$N“ª Ω°∏∫£ø› Ø¿√°π£¨“ª∏ˆ–˝…Ì£¨À´ ÷ΩÙŒ’$w"+YEL"£¨”…◊ÛºÁ–±≈¸$nµƒ$l"NOR,
	"force" : 180,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 33,
	"skill_name" : "∫£ø› Ø¿√",
	"damage_type" : "∏Ó…À"
]),
([      "action" : WHT "$Nª”ŒË$w"+WHT"£¨“ª’–°∏¥µµ—œÙœÙ°π£¨¡¨ø≥ ˝µ∂£¨√ø“ªµ∂µƒ¡¶µ¿∫ÕΩ«∂»∂º≤ªÕ¨£¨∫ˆ«·∫ˆ÷ÿ£¨
∆Î∆Î≈¸œÚ$n"NOR,
	"force" : 210,
	"dodge" : 15,
	"damage" : 60,
	"lvl" : 42,
	"skill_name" : "¥µµ—œÙœÙ",
	"damage_type" : "∏Ó…À"
]),
([      "action" : HIW "$N“ª’–°∏–Ø ÷ÃÏ—ƒ°π£¨ΩË‘æø’÷Æ ∆£¨”÷ «À´ ÷‘Àµ∂£¨$w"+HIW"∆∆ø’∂¯œ¬£¨–Æ∑Á…˘
≈¸œÚ$nµƒ$l£¨∑¢≥ˆº‚»Ò∆∆ø’µƒµ∂–•…˘"NOR,
	"force" : 240,
	"dodge" : 5,
	"damage" : 70,
	"lvl" : 51,
	"skill_name" : "–Ø ÷ÃÏ—ƒ",
	"damage_type" : "∏Ó…À"
]),
([      "action" : HIY "$N“ª’–°∏«ÈπÈ∫Œ¥¶°π£¨±©∫»…˘÷–À´ ÷≤ª◊°‘À∆$w"+HIY"£¨√øµπ∂º∏ﬂæŸπ˝Õ∑£¨ ±∂¯÷±≈¸£¨
 ±∂¯–±œ˜"NOR,
	"force" : 280,
	"dodge" : 20,
	"damage" : 80,
	"lvl" : 60,
	"skill_name" : "«ÈπÈ∫Œ¥¶",
	"damage_type" : "∏Ó…À"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="fumo-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª°£\n");
	if ((int)me->query_skill("beiming-shengong", 1) < 10)
		return notify_fail("ƒ„µƒ±±⁄§…Òπ¶ª∫ÚÃ´«≥°£\n");
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
	level   = (int) me->query_skill("ruyi-dao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("ƒ„ π”√µƒŒ‰∆˜≤ª∂‘°£\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("ƒ„µƒÃÂ¡¶≤ªπª¡∑»Á“‚µ∂°£\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ruyi-dao/" + action;
}
