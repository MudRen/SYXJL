// qingyan-zhang.c ����������

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ��������������˫�Ƽ�����һ�ŵ����İ�����������$n��$l",
	"force" : 100,
        "dodge" : 5,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫��һ�ƣ�һʽ���������ơ�������$n��$l��ȥ",
	"force" : 130,
        "dodge" : 10,
        "parry" : 15,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ���̺����Ρ����������һ��,���ƾ�ȡ$n��$l",
	"force" : 150,
        "dodge" : 15,
        "parry" : 20,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "�̺�����",
        "damage_type" : "����"
]),
([	"action" : "$N˫����������������һʽ���������졹������һ�����,ӡ��$n������",
	"force" : 200,
        "dodge" : 20,
        "parry" : 30,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��������һ�ݣ�ʹ��һʽ��������������˫�Ʋ�£����ֱ����$n��$l��ȥ",
	"force" : 240,
        "dodge" : 25,
        "parry" : 20,
	"damage": 50,
	"lvl" : 40,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�٣�ʹһʽ��������ɢ����˫�ƴ�����ɲ�ľ�����ֹ������ȴ�͵ػ���$n��$l",
	"force" : 280,
        "dodge" : 25,
        "parry" : 25,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "������ɢ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ���������졹������һ��ǿ�磬������Ϣ��һ������$n��ǰ��",
	"force" : 320,
        "dodge" : 30,
        "parry" : 30,
	"damage": 70,
	"lvl" : 60,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��׼���ᣬһ�С�����������������һȦһ�������ĳ����ƣ�����$n��$l",
	"force" : 360,
        "dodge" : 30,
        "parry" : 35,
	"damage": 80,
	"lvl" : 70,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ������ͬ������ɨ��һ�󾢷磬����˻˻֮����˫�������һ����裬�����ѻ���$n��$l��",
	"force" : 450,
        "dodge" : 40,
        "parry" : 45,
	"damage": 90,
	"lvl" : 80,
	"skill_name" : "����ͬ��",
        "damage_type" : "����"
]),
([	"action" : "$N��������������һʽ�����ħ����˫�ƽ����Ƴ������һ�����֮����������ɽ����������������$n",
	"force" : 540,
        "dodge" : 45,
        "parry" : 50,
	"damage": 110,
	"lvl" : 90,
	"skill_name" : "���ħ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������Ʊ�����֡�\n");
        if ((int)me->query_skill("jinyu-quan", 1) <20)
                return notify_fail("��Ľ���ȭ��򲻹����޷�ѧϰ����ȭ����\n");  
	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("��Ŀ���������򲻹����޷�ѧ���������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������������ơ�\n");
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
	level   = (int) me->query_skill("qingyan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("����������������������ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

/*string perform_action_file(string action)
{
	return __DIR__"qingyan-zhang/" + action;
}*/