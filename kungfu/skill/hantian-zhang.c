// hantian-zhang.c



inherit SKILL;



mapping *action = ({

        ([      "action":               

"$Nʹ��һ�С�������ʽ�������ƴ�������$n��$l",

                "dodge":                30,

                "parry":                10,

                "force":                100,

                "damage_type":  "����"

        ]),

        ([      "action":               

"$Nʹ��һ�С�������ʽ�������ƻ���Ϊʵ����$n��$l",

                "dodge":                10,

                "parry":                30,

                "force":                100,

                "damage_type":  "����"

        ]),

        ([      "action":               

"$Nʹ�������Ʒ���С����ʽ��������Ȱ�����$n��ǰ��һ������$n��$l",

                "dodge":                30,

                "parry":                10,

                "force":                50,

                "damage_type":  "����"

        ]),

        ([      "action":               

"$N˫��һ��ʹ����ѩ����ʽ������׼$n��$l�����ĳ�����",

                "dodge":                10,

                "parry":                30,

                "force":                60,

                "damage_type":  "����"

        ]),

        ([      "action":               

"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��������ķ�������$n$l",

                "dodge":                20,

                "parry":                30,

                "force":                140,

                "damage_type":  "����"

        ]),

        ([      "action":               

"$Nʹ�����������Ƕϡ�������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",

                "dodge":                70,

                "parry":                10,

                "force":                180,

                "damage_type":  "����"

        ]),

        ([      "action":               

"$N����������һ�С����������졹˫�Ʋ����Ƴ�",

                "parry":                40,

                "force":                220,

                "damage_type":  "����"

        ]),

});



int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }



mapping query_action(object me)

{

        if (random(me->query_skill("strike")) > 60 &&

            me->query_skill("force") > 50 &&

            me->query("neili") > 100 ) {

                me->add("neili", -100);

                return ([

                "action":"$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�\n",

                "action":"$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣\n",

                "action":"$n��һת��һ�С���������������$N����$w���֡�\n",

                "action": "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",

                "force": 300,

                "damage_type": "����"]);

        }

        return action[random(sizeof(action))];

}



int valid_learn(object me)

{

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

		return notify_fail("���������Ʊ�����֡�\n");

	if ((int)me->query_skill("doomforce", 1) < 10)

		return notify_fail("��Ĵ�Ѫ�񹦻���㣬�޷����������ơ�\n");

	if ((int)me->query("max_neili") < 60)

		return notify_fail("�������̫�����޷�����������");

	return 1;

}





int practice_skill(object me)

{

	if ((int)me->query("qi") < 30)

		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 8)

		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");

	if (me->query_skill("doomforce", 1) < 50)

		me->receive_damage("qi", 20);

	else

		me->receive_damage("qi", 30);

	me->add("neili", -5);

	return 1;

}



mixed hit_ob(object me, object victim, int damage_bonus, int factor)

{

        if( random(me->query_skill("doomforce")) > 10 ) 

	{

	victim->apply_condition("ice_poison", random(me->query_skill("doomforce")/10) + 1 +

	victim->query_condition("ice_poison"));

	}

}



string perform_action_file(string action)

{

	return __DIR__"doomstrike/" + action;

}

