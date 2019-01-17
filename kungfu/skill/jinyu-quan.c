// jinyu-quan.c ����ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$N��������һʽ��˫��������˫ȭֱȡ$n������",
	"force" : 50,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "˫����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������á�������һƬȭӰ, �͵ػ���$n��$l",
	"force" : 100,
	"dodge" : 10,
	"lvl" : 10,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N˫��һֿ��������Ϊǿ��ʹһ�С�����˫ȭ��$n��$l��ȥ",
	"force" : 150,
	"dodge" : 15,
	"lvl" : 20,
	"skill_name" : "",
	"damage_type" : "����"
]),
([	"action" : "$N����Ȧ���������⵱�أ����ֻ��ڳ��ϣ�һ�С��������⡹����$n��$l",
	"force" : 200,
	"dodge" : 20,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����һ�ᣬʹһ�С��������á���Ծ�ϰ�գ�˫ȭ���˸���Ȧ�������$n��$l",
	"force" : 250,
	"dodge" : 25,
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��ȭ������һ�ǡ���ʯ�ɽ𡹣��Ƴ���磬һ���Ӵ���$n������",
	"force" : 300,
	"dodge" : 0,
	"lvl" : 50,
	"skill_name" : "��ʯ�ɽ�",
	"damage_type" : "����"
]),
([	"action" : "$N�ҽ����أ����Ų��벽��ʩ���������������˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
	"force" : 350,
	"dodge" : 35,
	"lvl" : 60,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N����΢�ᣬ���㽻��һʽ����ʯΪ�������ճ���ȭ��˲�����ǣ�����$n���ؿ�",
	"force" : 400,
	"dodge" : 40,
	"lvl" : 80,
	"skill_name" : "��ʯΪ��",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qingyan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ȭ��������֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���������ȭ����\n");
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
	level   = (int) me->query_skill("jinyu-quan");
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������������ȭ����\n");
	me->receive_damage("qi", 20);
	me->add("neili", -5);
	return 1;
}

/*string perform_action_file(string action)
{
	return __DIR__"jinyu-quan/" + action;
} */