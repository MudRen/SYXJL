// dongyang-dao ���󵶷�
// Modified by Venus Oct.1997
inherit SKILL;
mapping *action = ({
([  "action": "$N���һ��������$wֱ������������һ���",
    "force" : 40,
    "attack": 30,
    "dodge" : 10,
    "lvl"   : 0,
    "damage": 95,
    "skill_name" : "ͣ����·",
    "damage_type" : "����"
]),
([  "action": "$NͻȻ���У�����$n��$l",
    "force" : 80,
    "attack": 35,
    "dodge" : 10,
    "damage": 110,
    "lvl"   : 10,
    "skill_name" : "ͯ�ӹһ�",
    "damage_type" : "����"
]),
([  "action": "$N���е�$w�����任�����������ͻȻֱ��$n��$l",
    "force" : 110,
    "attack": 40,
    "dodge" : 15,
    "damage": 110,
    "lvl"   : 30,
    "skill_name" : "�ƴ�����",
    "damage_type" : "����"
]),
([  "action": "$N���е�$w��Ȼ��ת������һ�ŵ�Ӱ��ֱ��$n",
    "force" : 130,
    "attack": 45,
    "dodge" : 25,
    "damage": 125,
    "lvl"   : 50,
    "skill_name" : "���ż�ɽ",
    "damage_type" : "����"
]),
([  "action": "$N����$wһ����˫�ֳ����������У�����$n��$l",
    "force" : 140,
    "attack": 40,
    "dodge" : 20,
    "damage": 125,
    "lvl"   : 80,
    "skill_name" : "��Ϫ����",
    "damage_type" : "����"
]),
([  "action": "$N��Хһ�������е�$w��ס�Ļζ����������ѵ�����$n",
    "force" : 180,
    "attack": 45,
    "dodge" : 25,
    "damage": 135,
    "lvl"   : 100,
    "skill_name" : "�Ź�����",
    "damage_type" : "����"
]),
([  "action": "$Nһת���ѱ���ȫ������$n��ͻȻ˫��һת��$w��$N������˳���",
    "force" : 200,
    "attack": 45,
    "dodge" : 15,
    "damage": 140,
    "lvl"   : 120,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action": "$N��ȻǰϮ������$w����һ����â�����Ĵ���$n",
    "force" : 210,
    "attack": 50,
    "dodge" : 30,
    "damage": 160,
    "lvl"   : 150,
    "skill_name" : "ͣ����·",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");

    if ((int)me->query_skill("force") < 30)
        return notify_fail("����ڹ���򲻹���\n");

    if ((int)me->query_skill("blade", 1) < (int)me->query_skill("dongyang-dao", 1))
        return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ķ��󵶷���\n");

    if ((int)me->query_skill("blade", 1) < (int)me->query_skill("dongyang-dao", 1))
        return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ķ��󵶷���\n");

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
    level   = (int) me->query_skill("dongyang-dao",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");

    if ((int)me->query("qi") <750)
        return notify_fail("����������������󵶷���\n");

    if ((int)me->query("neili") < 55)
        return notify_fail("����������������󵶷���\n");

    me->receive_damage("qi", 60);
    me->add("neili", -42);

    return 1;
}
