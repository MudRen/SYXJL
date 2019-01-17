// qiuge-daofa.c ��赶��
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action":"$Nʹһ�С�һҶ��Ƽ��󺣡�������$wһ�ڣ����μ�����ɣ����˺�һ������$n��$l��",
	"force" : 120,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "һҶ��Ƽ���",
	"damage_type":  "����"
]),
([      "action":"$N$w�����������⣬һ�С������δ�����꡹����������$n��$l��",
	"force" : 140,
	"dodge" : -10,
	"damage": 40,
	"lvl" : 15,
	"skill_name" : "�����δ������",
	"damage_type":  "����"
]),
([      "action":"$N����$w����������ˮ��һ�С�˥��б�������֡���бб����$n��$l",
	"force" : 160,
	"dodge" : 5,
	"damage": 70,
	"lvl" : 30,
	"skill_name" : "˥��б��������",
	"damage_type":  "����"
]),
([      "action":"$N����$w���⼤����һ�С�����Ӱ�հ����̡���ն��$n��",
	"force" : 180,
	"dodge" : 10,
	"damage": 90,
	"lvl" : 45,
	"skill_name" : "����Ӱ�հ�����",
	"damage_type":  "����"
]),
([      "action":"$N����$w���裬�������Ŵشأ�һ�С����ܻ���֪��ɫ����ƮƮ������$n��ȥ",
	"force" : 220,
	"dodge" : 15,
	"damage": 110,
	"lvl" : 60,
	"skill_name" : "���ܻ���֪��ɫ",
	"damage_type":  "����"
]),
([      "action":"$N����$w����ɭȻ��һ�С���Ƽ��Զ��������ֱ��$n��$l",
	"force" : 280,
	"dodge" : 25,
	"damage": 130,
	"lvl" : 75,
	"skill_name" : "��Ƽ��Զ������",
	"damage_type":  "����"
]),
([      "action":"$Nʹһ�С��ͷ������仨�졹������$w�ڶ����������ն��$n��$l",
	"force" : 340,
	"dodge" : 15,
	"damage": 150,
	"lvl" : 90,
	"skill_name" : "�ͷ������仨��",
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{ 
/*
       if( (string)me->query("gender") != "����" )
                return notify_fail(HIW "��赶����ֻ�����Բ��������书��\n"NOR);
*/
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������������\n");
	return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$nʹ��һ�С���ҡɽ�������������е�$vɢ��˿˿��������$N��$w��\n",
	"$n����$v���������һ�С����������б��������Ӱ��ͻȻ����һ�ƹ�â�Ӳ��滮��$N֮�ؾȡ�\n",
	"$n����΢�٣����е�$v����һ�����⣬һ�С����������һ�С�������$N��$w��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С�˪���Ҷ����������е�$v����������$N�Ĺ����沨��ɢ��\n",
"$n���μ��ˣ�����$v���·��裬һ�С������������󡹣���ס$N����ʽ��\n",
"$n���е�$v�����䵶����һ�С�������Ӱ���������������ࡣ\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
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
	level   = (int) me->query_skill("qiuge-daofa",1);
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
		return notify_fail("���������������赶����\n");
	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"qiuge-daofa/" + action;
}
