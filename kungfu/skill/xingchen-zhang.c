// xingchen-zhang.c �ǳ��Ʒ�
// by QingP

#include <ansi.h>

inherit SKILL;

string skill_for_advanced = "huagong-dafa";
string basic_skill_for_advanced = "poison";

mapping *normal_action = ({
([      "action": "$N���ζ�Ȼ��죬��ת��������$n��˫���������裬���Ž��ȣ�����$n��$l",
	"dodge": 40,
	"force": 330,
	"poison": 30,
	"damage_type": "����"
]),
([      "action": "$N�������磬Ѹ���ޱ�����$n��˫����������$n�����ߴ�ҪѨ",
	"dodge": 15,
	"force": 370,
	"poison": 45,
	"damage_type": "����"
]),
([	"action": "$N������Ʈ�ݣ�˫����һ�Ի�����������Ѳ�������������$n$l",
	"dodge": 27,
	"force": 300,
	"poison": 60,
	"damage_type": "����"
]),
([	"action": "$N�������������������Ŀ�������������ӰƮƮ���������գ�����$nҪ��",
	"dodge": 10,
	"force": 375,
	"poison": 75,
	"damage_type": "����"
]),
});

mapping *advanced_action = ({
([      "action": "$N����Ʈ�����㲻��أ���������һ�����������磬˫���ԡ��������䡹֮�ƻ���$n��$l",
        "dodge": 60,
        "force": 510,
	"damage": 22,
        "poison": 70,
	"lvl": 0,
        "damage_type": "����"
]),
([	"action": "$N�������Ѳ�����˲��ó�������Ӱ�����ֺ϶�Ϊһ��һ�С����κ�Ӱ������$n����\nδ��֮ʱ��������Ӱ������ǵذ���$nϮ��",
	"dodge": 45,
	"force": 570,
	"damage": 27,
        "poison": 100,
	"lvl": 20,
	"damage_type": "����"
]),
([      "action": "$N����ٿ��һ�Σ�����Ϊָ��������������ָӰ�硸ǧ�����롹�����$n����ҪѨ",
        "dodge": 55,
        "force": 640,
	"damage": 22,
        "poison": 170,
	"lvl": 45,
        "damage_type": "����"
]),
([	"action": "$N�۱����⣬ʹ�����׶����졹����Ե��������������͸�䵶â��������â���ϣ�\n����������ɣ�����$n��$l",
	"dodge": 40,
	"force": 600,
	"damage": 29,
        "poison": 210,
	"lvl": 70,
	"damage_type": "����"
]),
([	"action": "$N�������ݡ�����������ĳ�һ�ƣ�������Ӱһ��ʮ��ʮ�ð٣��Ƴʡ��ǻ���ԭ������\n$n��$l",
	"dodge": 70,
	"force": 700,
	"damage": 24,
        "poison": 200,
	"lvl": 100,
	"damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry";
}

int valid_combine(string combo) { return combo=="wugong-zhao"; }

mapping query_action(object me, object weapon)
{
	int i, level;
	
	if ( me->query_skill(skill_for_advanced, 1)
	&&   me->query_skill_mapped(basic_skill_for_advanced) == skill_for_advanced )
	{
		level = (int) me->query_skill(skill_for_advanced, 1);
		for(i = sizeof(advanced_action); i > 0; i--)
			if(level > advanced_action[i-1]["lvl"])
				return advanced_action[NewRandom(i, 5, level/5)];
	}
	else {
/*		if (random(me->query_skill("strike")) > 30
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
		}*/
		return normal_action[random(sizeof(normal_action))];
	}
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ǳ��Ʒ�������֡�\n");
	if ((int)me->query_skill("beiming-zhenqi", 1) < 10)
		return notify_fail("��ı�ڤ������򲻹����޷����ǳ��Ʒ���\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("�������̫�����޷����ǳ��Ʒ���\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ǳ��Ʒ�������֡�\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˣ��������ǳ��Ʒ���\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("��������������ǳ��Ʒ���\n");
	if (me->query_skill("xingchen-zhang", 1) < 50)
		me->receive_damage("qi", 15);
	else
		me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

/*mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if ( me->query_skill(skill_for_advanced, 1)
	&&   me->query_skill_mapped(basic_skill_for_advanced) == skill_for_advanced )
	{
		if( damage_bonus < 100 ) return 0;

		if( random(damage_bonus/2) > victim->query_str() )
		{
			victim->receive_wound("qi", (damage_bonus - 100) / 2 );
			return HIB "������Ӱ�׷ɣ��������ƣ����Ź���������죬������������֮����\n" NOR;
		}
	}
	else if( random(me->query_skill("xingchen-zhang")) > 10 )
	{
		victim->apply_condition("xx_poison", random(me->query_skill("xingchen-zhang")/10)
		+ 1 + victim->query_condition("xx_poison"));
	}
}*/

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if ( me->query_skill(skill_for_advanced, 1)
	&&   me->query_skill_mapped(basic_skill_for_advanced) == skill_for_advanced
	&&    random(me->query_skill(skill_for_advanced)) > 10 )
	{
		victim->apply_condition("xx_poison", random(me->query_skill("skill_for_advanced")/7)
		+ 1 + victim->query_condition("xx_poison"));
	}
}

string perform_action_file(string action)
{
	return __DIR__"xingchen-zhang/" + action;
}