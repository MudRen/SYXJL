// yanxing-dao.c ���е�
inherit SKILL;
mapping *action = ({
([	"action" : "$Nʹ�������־���������һ�࣬�ù�$n�����Żӵ�ն��$n��$l",
	"force" : 180,
        "dodge" : -10,
        "parry" : 5,
	"damage": 40,
	"lvl" : 0,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ�����־����������������⣬����$wˢ��һ�����϶�����$n����",
	"force" : 200,
        "dodge" : -10,
        "parry" : 10,
	"damage": 50,
	"lvl" : 10,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ�����־��������ŵ�أ�˫����$w��������$n��$l��ȥ�",
	"force" : 220,
        "dodge" : -5,
        "parry" : 5,
	"damage": 60,
	"lvl" : 20,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹһʽ��ӡ�־������Ų��󻬣�����$w�����ջأ�ͻȻ����һ��ն��$n��$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 5,
	"damage": 70,
	"lvl" : 30,
	"skill_name" : "���־�",
	"damage_type" : "����",
]),
([	"action" : "$N����$w����һʽ�����־�����$w����������Ȧ�����쵶��������$n��$l",
	"force" : 280,
        "dodge" : 10,
        "parry" : 5,
	"damage": 80,
	"lvl" : 40,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N����һ����˫�ֺ�ִ$w��һʽ�����־���������$wֱ����$n��˫��",
	"force" : 320,
        "dodge" : 15,
        "parry" : 15,
	"damage": 90,
	"lvl" : 50,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ��̽�־���������$w΢���������ѵ�ˮ����ٵ���$n��$l",
	"force" : 360,
        "dodge" : 15,
        "parry" : 15,
	"damage": 100,
	"lvl" : 60,
	"skill_name" : "̽�־�",
	"damage_type" : "����"
]),
([	"action" : "$N����һ����˫���յ���һʽ�����־���������ֱ���������󵶷���$n��ȥ",
	"force" : 400,
        "dodge" : 20,
        "parry" : 10,
	"damage": 110,
	"lvl" : 70,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ�����־������ص������һ����ˤ��һ�����⣬����$n��$l",
	"force" : 450,
        "dodge" : 10,
        "parry" : 20,
	"damage": 120,
	"lvl" : 80,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һʽ�����־�����������$w����޿��ܵķ����ȥ������һת��ȴն��$n��$l",
	"force" : 500,
        "dodge" : 5,
        "parry" : 25,
	"damage": 130,
	"lvl" : 90,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="yanxing-dao";}
int valid_learn(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("yanxing-dao",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
        if ((int)me->query_skill("jinding-mianzhang",1) < 20)
                return notify_fail("��Ľ����ƻ��̫ǳ��\n");
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
	level   = (int) me->query_skill("yanxing-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
        if (me->query("class")!="bonze" && (int)me->query_skill("yanxing-dao",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������е���\n");
	me->receive_damage("qi", 35);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"yanxing-dao/" + action;
}

