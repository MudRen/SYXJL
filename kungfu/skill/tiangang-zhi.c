// tiangang-zhi.c -���ָ
// create bye cuer
inherit SKILL;
mapping *action = ({
([	"action" : "$N��ָƮ�������������յУ���ָ���˸�ԲȦ��һʽ��������ġ���Ȧ�д�������$n��$l",
	"force" : 80,
        "dodge" : -5,
	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N�������У�һʽ��������̶������ָ��Ҹ������ָ��$n����ǰ",
	"force" : 100,
        "dodge" : -5,
	"lvl" : 10,
	"skill_name" : "������̶",
        "damage_type" : "����"
]),
([	"action" : "$N����б�У�һʽ�����߾��ɡ������ְ��ƣ�����һָ�������$n��$l��ȥ",
	"force" : 120,
        "dodge" : 5,
	"lvl" : 20,
	"skill_name" : "���߾���",
        "damage_type" : "����"
]),
([	"action" : "$N��ȻһЦ��һʽ��������ɽ����һ����˫��бָ�����Ƶ���$n��$l",
	"force" : 150,
        "dodge" : 5,
	"damage": 15,
	"lvl" : 30,
	"skill_name" : "������ɽ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ����һʽ��������������˫�ֻû�������ָӰ�������ŷ���֮��������$n��ȫ��",
	"force" : 200,
        "dodge" : 15,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ����ǰ��ʮָ�濪��һʽ���ض�ɽҡ����ָ��$n�������Ѩ",
	"force" : 240,
        "dodge" : 20,
	"damage": 25,
	"lvl" : 50,
	"skill_name" : "�ض�ɽҡ",
        "damage_type" : "����"
]),
([	"action" : "$N˫�Ʒ��ɣ�һʽ��ˮ�����¡���ָ�˱ų�����������������$n��ȫ��",
	"force" : 300,
        "dodge" : 25,
	"damage": 30,
	"lvl" : 60,
	"skill_name" : "ˮ������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��̩ɽѹ��������ָ���У�һ����������ٱ��ָ�磬������$n��ͷ�Ͽ�ȥ",
	"force" : 350,
        "dodge" : 30,
	"damage": 35,
	"lvl" : 70,
	"skill_name" : "̩ɽѹ��",
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinding-mianzhang"; }
int valid_learn(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("tiangang-zhi",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ָ������֡�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ���ָ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷������ָ��\n");
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
	level   = (int) me->query_skill("tiangang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{        
        if (me->query("class")!="bonze" && (int)me->query_skill("tiangang-zhi",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n"); 
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������ָ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
