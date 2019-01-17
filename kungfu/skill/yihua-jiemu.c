// yihua-jiemu.c �ƻ���ľ
// by rtm 00.03

inherit SKILL;

string *parry_msg = ({
	"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ������������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

string *dodge_msg = ({
	"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ������������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
       return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("yihua-jimu", 1);

        if ( me->query("gender") == "����" && lvl > 99)
                return notify_fail("�ƻ���ľ���ƻ�����������,�����������ӡ�\n");

        if ((int)me->query_skill("yihua-force", 1) < 150)
                return notify_fail("����ƻ��ķ�����������ô��ѧ�ƻ���ľ�أ�\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("����ô������ڹ�����ѧ�ƻ���ľ��\n");

	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("����ô����������ѧ�ƻ���ľ��\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");

        return 1;
}

string perform_function_file(string func)
{
        return __DIR__"yihua-jiemu/" + func;
}