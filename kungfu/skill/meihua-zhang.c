// meihua-zhang.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С�������ѡ�����׼$n��$l��ƮƮ��ɨȥ",
		"dodge":		10,
		"parry":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N�������֣�һ�С��������ۡ�����$n��$l��ȥ",
		"dodge":		10,
		"parry":		40,
		"damage_type":	"����"
	]),
		([	"action":		"$N������Σ����֡�������¥����$n��l����",
		"dodge":		20,
		"parry":		60,
		"damage_type":	"����"
	]),
        ([      "action":               "$N����΢�֣�����һ��ʹ��һ�С����ֻ�ʱ����ץ��$n��$l",
                "dodge":                50,
                "parry":                80,
                "force":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               "$Nٿ��һ��ת��˫��һ����һ����˼��ֱ��$n��$l",
                "dodge":                10,
                "parry":                120,
                "force":                210,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ�����ƮƮ��һ�С������г����$n��$l",
                "dodge":                20,
                "parry":                140,
                "force":                240,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������$n��$l����������һ�С�����üͷ����������ͬһ��λץ��",
                "parry":                160,
                "force":                300,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               "$N������Σ������ճ�ȭ��һ�С�ȴ����ͷ������$n��$l",
                "dodge":                20,
                "parry":                160,
                "force":                340,
                "damage_type":  "����"
        ]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��÷���Ʊ�����֡�\n");
	if ((int)me->query_skill("guiyuan-dafa", 1) < 20)
		return notify_fail("��Ĺ�Ԫ�󷨻�򲻹����޷�ѧ÷���ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���÷���ơ�\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("jing", 30);
	return 1;
}
int effective_level() { return 15;}

string *parry_msg = ({
        "$nһ�С���ź���������������ͻ�$N�����š�\n",
        "$n������ϣ�����һ�С�����˭�Ľ����������Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�����Ʈ��ˮ������������$N������\n",
        "$nһ�С������޼ƿ�������������һ��$N���֣���ƫ��$N�Ĺ��ơ�\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С�����Ũ�Ƴ����硹���Ƶ�$N��;���С�\n",
        "$n����������һ�С�����Ѿƻƻ�󡹣���$N֮�ؾȡ�\n",
        "$n���ַ��£�����һ�С�����Ʈ��ˮ����������$N���ڳ��⡣\n",
        "$n˫�������ʹ��һ�С������޼ƿ���������$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",

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
	return -20;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
	return __DIR__"meihua-zhang/" + action;
}
