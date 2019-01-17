// yiyang-zhi.c һ��ָ��

inherit SKILL;

mapping *action = ({
([	"action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ����������������$n��$l",
	"force" : 200,
        "dodge" : -5,
	"lvl" : 0,
	"damage": 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N�������У�һʽ��³�����ա�����ָ��Ҹ������ָ��$n����ǰ",
	"force" : 300,
        "dodge" : -5,
	"lvl" : 30,
	"damage": 80,
	"skill_name" : "³������",
        "damage_type" : "����"
]),
([	"action" : "$N����б�У����ְ��ƣ�����һʽ��������ѩ������$n��$l����",
	"force" : 350,
        "dodge" : 5,
	"lvl" : 45,
	"damage": 95,
	"skill_name" : "������ѩ",
        "damage_type" : "����"
]),
([	"action" : "$N˫Ŀ΢����һʽ���������졹��˫�ֻû���ǧ�ٸ�ָӰ������$n��$l",
	"force" : 400,
        "dodge" : 5,
	"damage": 110,
	"lvl" : 60,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ�����ս����������ƻ�ס�������бָ���죬���Ƶ���$n��$l",
	"force" : 500,
        "dodge" : 15,
	"damage": 130,
	"lvl" : 80,
	"skill_name" : "���ս���",
        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ����ǰ��ʮָ�濪��һʽ�����ﳯ������ָ��$n�������Ѩ",
	"force" : 550,
        "dodge" : 20,
	"damage": 150,
	"lvl" : 100,
	"skill_name" : "���ﳯ��",
        "damage_type" : "����"
]),
([	"action" : "$N˫�Ʒ��ɣ�һʽ������������ָ�˱ų�����������������$n��ȫ��",
	"force" : 600,
        "dodge" : 25,
	"damage": 160,
	"lvl" : 120,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��������̩������ָ���У�һ����������ٱ�ĵ�����������$n��$l��ȥ",
	"force" : 600,
        "dodge" : 30,
	"damage": 200,
	"lvl" : 140,
	"skill_name" : "������̩",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��һָ���꡹��˫��ʳָ���棬ָ�����һ�����������$n��$l",
	"force" : 550,
        "dodge" : 35,
	"damage": 240,
	"lvl" : 160,
	"skill_name" : "һָ����",
        "damage_type" : "����"
]),
([	"action" : "$N����������ǰ��һʽ��һָ���졹������ʳָ��סĴָ���������$nһ��",
	"force" : 650,
        "dodge" : 50,
	"damage": 300,
	"lvl" : 180,
	"skill_name" : "һָ����",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="liumai-shenjian" || combo=="duanjia-jian"; }

int valid_learn(object me)
{       
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һ��ָ������֡�\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷���һ��ָ��\n");
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
		level   = (int) me->query_skill("yiyang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������һ��ָ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
        write("�㰴����ѧ����һ��һ��ָ��\n");
        return 1;
}

string perform_action_file(string action)
{
	return "/kungfu/skill/yiyang-zhi/" + action;
}

