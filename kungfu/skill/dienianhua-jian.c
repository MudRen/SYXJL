#include <ansi.h>

inherit SKILL;

mapping *action = ({

	([	

		"action":		"$Nʹһ�С�����Σ����ϸϸ����������ҡ������$wһ�ڣ���$n��

$l��ȥ",

		"dodge":		50,

		"force":		170,

		"damage_type":	"����"

	]),

	([	

		"action":		"$N���ΰεض�������$w�趯�����콣��ɭɭ��һ�С���ɫ�̹�����

����$n��$l",

		"dodge":		-70,

		"force":		200,

		"damage_type":	"����"

	]),

	([	

		"action":		"$N����$w��â������һ�С�����˭��ƾ���⡹��˲������$n��

$l��������",

		"dodge":		-40,

		"damage":		90,

		"damage_type":	"����"

	]),

	([	

		"action":		"$N����$wһȦ����������ɳ����ͻȻ����һ���������������⣬һ��

��������ͼһ������ס$n��$l",

		"dodge":		-40,

		"damage":		40,

		"damage_type":	"����"

	]),

	([	

		"action":		"$N$w�������ó����콣Ӱ�����Ŵشأ�һ�С��´������ղ��ڡ���

$n$l��ȥ",

		"dodge":		60,

		"damage":		120,

		"damage_type":	"����"

	]),

	([	

		"action":		"$N����Ծ������$w�����佣����һ�С�Ϊ���������㲡���ס

$n��ȫ��",

		"dodge":		-60,

		"damage":		150,

		"damage_type":	"����"

	]),

});



int valid_learn(object me)

{ 

/*
       if( (string)me->query("gender") != "Ů��" )

                return notify_fail("���������ֻ��Ů�Բ��������书��\n");

*/
	if ((int)me->query("max_neili") < 150)

		return notify_fail("�������������\n");

	return 1;

}

int valid_enable(string usage)

{

	return usage=="sword" || usage=="parry";

}



mapping query_action(object me, object weapon)

{

	return action[random(sizeof(action))];

}

int practice_skill(object me)

{

	object weapon;



	if (!objectp(weapon = me->query_temp("weapon"))

	|| (string)weapon->query("skill_type") != "sword")

		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 50)

		return notify_fail("����������������������\n");

	me->receive_damage("qi", 25);

		return 1;

}

int valid_effect(object me, object weapon, string name, int skill)

{

}

string perform_action_file(string action)

{

	return __DIR__"dienianhua-jian/" + action;

}



int effective_level() { return 10;}



string *parry_msg = ({

        "$nʹ������Դ̽�ġ�������$v�������ۣ���$N���е�$w��ƫ�˳�ȥ��\n",

	"$n$vƮ��������һ�С��ɷ���𽡹�������벻���ĽǶȼ�ס��$N���е�$w��\n",

	"$n���е�$v����������һ�С��Űؾ��ɡ�������$N��$w����ָ��\n",

	"$n���е�$v������ɣ�������������Ⱥɽ��һ�С�Ⱥ����䡹����ס��$N��$w��\n",

});



string *unarmed_parry_msg = ({

        "$n����$vԲת������������һ�С���ɽ���ơ���ǿ���Ľ����Ƶ�$N�������ˡ�\n",

	"$n����$v�ĳ����ݽ�����һ�С�������ʤ��������$Nվ�����ȡ�\n",

	"$n$v��Σ����潣�ƣ��ڿ���������һ�С���ȥ���⡹����ʧ����Ӱ���١�\n",

	"$nת����$vһ�С�������塹������һƬ��â�����Լ�ȫ�������ܲ�͸�硣\n",

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


