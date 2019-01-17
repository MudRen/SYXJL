// ruyi-dao.c ���⵶�  by rhxlwd 99.02
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([     "action" : HIM "$N����$w"+HIM"бָ��һ�С�˫��˫�ɡ�����ת$w���Ե�����$n��$l��ȥ"NOR,
	"force" : 120,
	"dodge" : -10,
	"damage" : 10,
	"lvl" : 0,
	"skill_name" : "˫��˫��",
	"damage_type" : "����"
]),
([      "action" : HIG "һʽ��������������$N���ֳֵ����������������$w"+HIG"��������������
$n��$l"NOR,
	"force" : 130,
	"dodge" : -10,
	"damage" : 20,
	"lvl" : 8,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
  ([      "action" : HIC "$N����ʹ����������Ϭ������Ȼ������Ȼ�����ֳ�$w"+HIC"��һ������Ϯ��������
����һ��������ն��$n"NOR,
	"force" : 140,
	"dodge" : -5,
	"damage" : 30,
	"lvl" : 16,
	"skill_name" : "������Ϭ",
	"damage_type" : "����"
]),
([      "action" : MAG "$Nһ�С��������ԡ���$w"+MAG"��Ӱ���ε��ٷ���һ������ֱ����$n��$l"NOR,
	"force" : 160,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 24,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : YEL "$Nһʽ������ʯ�á���һ������˫�ֽ���$w"+YEL"�������б��$n��$l"NOR,
	"force" : 180,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 33,
	"skill_name" : "����ʯ��",
	"damage_type" : "����"
]),
([      "action" : WHT "$N����$w"+WHT"��һ�С�����������������������ÿһ���������ͽǶȶ���ͬ��������أ�
��������$n"NOR,
	"force" : 210,
	"dodge" : 15,
	"damage" : 60,
	"lvl" : 42,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : HIW "$Nһ�С�Я�����ġ�����Ծ��֮�ƣ�����˫���˵���$w"+HIW"�ƿն��£�Ю����
����$n��$l�����������ƿյĵ�Х��"NOR,
	"force" : 240,
	"dodge" : 5,
	"damage" : 70,
	"lvl" : 51,
	"skill_name" : "Я������",
	"damage_type" : "����"
]),
([      "action" : HIY "$Nһ�С����δ�������������˫�ֲ�ס����$w"+HIY"��ÿ�����߾ٹ�ͷ��ʱ��ֱ����
ʱ��б��"NOR,
	"force" : 280,
	"dodge" : 20,
	"damage" : 80,
	"lvl" : 60,
	"skill_name" : "���δ�",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="fumo-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("beiming-shengong", 1) < 10)
		return notify_fail("��ı�ڤ�񹦻��̫ǳ��\n");
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
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������⵶��\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ruyi-dao/" + action;
}
