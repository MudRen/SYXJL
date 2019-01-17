// wugong-zhao.c

// by QingP



#include <ansi.h>



inherit SKILL;



mapping *action = ({

([      "action": "$N˫�۱�����һ�С���צ�ѻ꡹���ó�����צӰ����$n˫�����д�Ѩȫ������צ��",

	"dodge": 25,

	"parry": 10,

	"force": 300,

        "damage": 14,

	"poison": 20,

	"damage_type":  "ץ��"

]),

([      "action": "$N˫צ����һ��һ����һ�С�������ǡ���˫צ���總��֮����ʼ�ղ���$n��$l�ֺ�",

	"dodge": 40,

	"parry": 20,

	"force": 270,

	"damage": 17,

        "poison": 70,

	"damage_type":  "ץ��"

]),

([      "action": "$Nʹ��������զ�֡�������Ȱ�����$n��ǰ��һצ����$n��$l",

	"dodge": 70,

	"parry": 10,

	"force": 200,

	"damage": 13,

        "poison": 40,

	"damage_type":  "ץ��"

])

});



int valid_enable(string usage)

{

	return usage=="claw" || usage=="parry";

}



int valid_combine(string combo) { return combo=="xingchen-zhang"; }



mapping query_action(object me, object weapon)

{

        return action[random(sizeof(action))];

}



int valid_learn(object me)

{

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

		return notify_fail("���������צ������֡�\n");

	if ((int)me->query_skill("beiming-zhenqi", 1) < 10)

		return notify_fail("��ı�ڤ������򲻹����޷����������צ��\n");

	if ((int)me->query("max_neili") < 30)

		return notify_fail("�������̫�����޷����������צ��\n");

	return 1;

}



int practice_skill(object me)

{

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

		return notify_fail("���������צ������֡�\n");

	if ((int)me->query("qi") < 30)

		return notify_fail("�������̫���ˣ��������������צ��\n");

	if ((int)me->query("neili") < 30)

		return notify_fail("��������������������צ��\n");

	if (me->query_skill("wugong-zhao", 1) < 50)

		me->receive_damage("qi", 15);

	else

		me->receive_damage("qi", 30);

	me->add("neili", -10);

	return 1;

}



mixed hit_ob(object me, object victim, int damage_bonus)

{

	if( damage_bonus < 110 ) return 0;



	if( random(damage_bonus/4) > victim->query_str()/2 ) {

		victim->receive_wound("qi", (damage_bonus - 100) / 2 );

		switch(random(3)) {

			case 0: return HIR"��������������һ�����죬�����ǹ����������\n"NOR;

			case 1: return HIR"$N����һ�£�$n��$l������������һ�����죡\n"NOR;

			case 2: return HIR"ֻ����$n��$l��������һ�� ...\n"NOR;

		}

	}

}