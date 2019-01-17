// xingxiu-dugong.c ���޶���
// by QingP

inherit SKILL;

mapping *action = ({
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
        "dodge": 30,
        "force": 330,
        "poison": 30,
        "damage_type": "����"
]),
([      "action": "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
        "dodge": -15,
        "force": 340,
        "poison": 45,
        "damage_type": "����"
]),
([	"action": "$N˫������$n��$l������δ����һ�󸯳������������������������$nϮ��",
	"dodge": 20,
	"force": 300,
        "poison": 60,
	"damage_type": "����"
]),
([	"action": "$N�۱����⣬��Ե����������ɫ��˫�Ʒ׷ɣ�������Ӱ����$n��$l",
	"dodge": 10,
	"force": 375,
        "poison": 75,
	"damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="poison" || usage=="parry";
}

mapping query_action(object me)
{
        if (random(me->query_skill("strike")) > 30
	&& me->query_skill("force") > 40 && me->query("neili") > 70 )
	{
		if (random(1) > 0 && objectp(present("bonfire", environment(me))))
 		{
 			me->add("neili",-20);
 			 return ([
 			"action": "$N�͵����Ӽ����������ݰ���ת��ʮ���Ȧ��������������������\n���ذ��𣬱���һ����ǽ��$nѹ��",
 			"force": 550,
 			"damage_type": "����"]);
 		}
		else
		{
			me->add("neili", -15);
 			return ([
 			"action": "$N��ɫ�ҵ�����Ȼ������ҧ����⣬һ����Ѫ��$n��ȥ",
 			"force": 400,
 			"damage_type": "����"]);
 		}
	}
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if ((int)me->query_skill("beiming-zhenqi", 1) < 10)
		return notify_fail("��ı�ڤ������򲻹����޷������޶�����\n");
	if ((int)me->query_skill("poison", 1) < 10)
		return notify_fail("��Ļ���������򲻹����޷������޶�����\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("�������̫�����޷������޶�����\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����޶���������֡�\n");
	return 1;
}


int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����޶���������֡�\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˣ����������޶�����\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("����������������޶�����\n");
	if (me->query_skill("xingxiu-duzhang", 1) < 50)
		me->receive_damage("qi", 15);
	else
		me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("xingxiu-dugong")) > 10 )
	{
		victim->apply_condition("xx_poison", random(me->query_skill("xingxiu-dugong")/10)
		+ 1 + victim->query_condition("xx_poison"));
	}
}

string perform_action_file(string action)
{
	return __DIR__"xingxiu-dugong/" + action;
}