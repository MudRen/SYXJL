// fanyun-zhang.c ������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһʽ���̺����졹������΢��������է��է�ϣ��͵ز���$n��$l",
	"force" : 180,
	"dodge" : 5,
	"parry" : 20,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "�̺�����",
	"damage_type" : "����"
]),
([      "action" : "$N�����������죬һʽ�����ѪӰ���������纣ˮ����$n��ȥ",
	"force" : 240,
	"dodge" : 10,
	"parry" : 25,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "���ѪӰ",
	"damage_type" : "����"
]),
([      "action" : "$N��������һ�ݣ�ʹ��һʽ�������ǳ�����˫��һ̯����ֱ����$n��$l��ȥ",
	"force" : 300,
	"dodge" : 15,
	"parry" : 30,
	"damage": 45,
	"lvl" : 40,
	"skill_name" : "�����ǳ�",
	"damage_type" : "����"
]),
([      "action" : "$N����һ�䣬ʹһʽ����е�ȱ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
	"force" : 360,
	"dodge" : 20,
	"parry" : 35,
	"damage": 60,
	"lvl" : 60,
	"skill_name" : "��е�ȱ",
	"damage_type" : "����"
]),
([      "action" : "$Nͻ��һ�С�����׷�꡹��˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
	"force" : 420,
	"dodge" : 35,
	"parry" : 40,
	"damage": 75,
       "lvl" : 80,
	"skill_name" : "�ƺ�����",
	"damage_type" : "����"
]),
([      "action" : "$Nһʽ��������ա����������ϴ������࣬˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
	"force" : 480,
	"dodge" : 40,
	"parry" : 50,
	"damage": 90,
	"lvl" : 100,
	"skill_name" : "�������",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("wuxin-jing", 1) < 20)
		return notify_fail("������ľ���򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������ơ�\n");
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
	level   = (int) me->query_skill("liuhe-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuhe-zhang/" + action;
}
