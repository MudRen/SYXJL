// wuluo-zhang.c -����������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ��һ�С�һ�����̡�������ֱ�������������$n��ǰ����ȥ��",
        "force" : 200,
        "dodge" : 50,
        "damage": 110,
        "lvl" : 0,
        "skill_name" : "һ������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�С���ϼ���ա�������Ծ��˫��ͬ��������$n��$l",
        "force" : 200,
        "dodge" : 50,
        "damage": 100,
        "lvl" : 8,
        "skill_name" : "��ϼ����",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ����˿���ơ�����ָ������û��������$n�ĸ���Ҫ��",
        "force" : 200,
        "dodge" : 50,
        "damage": 110,
        "lvl" : 16,
        "skill_name" : "��˿����",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N˫�ֲ��ƣ�һʽ���������ࡹ��������$n��",
        "force" : 200,
        "dodge" : 100,
        "damage": 130,
        "lvl" : 24,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С��컨��׹��������˷�����������Ӱ��һ��ͻ��������$n���ؿ�",
        "force" : 220,
        "dodge" : 50,
        "damage": 140,
        "lvl" : 40,
        "skill_name" : "�컨��׹",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ��������ð���̣�һʽ���������ء�������$n��$l",
        "force" : 270,
        "dodge" : 50,
        "damage": 140,
        "lvl" : 48,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ����Ͷ��ϡ�,˫�����죬������հ������$n��ȫ��ҪѨ",
        "force" : 330,
        "dodge" : 50,
        "damage": 170,
        "lvl" : 54,
        "skill_name" : "ɽ������",
        "damage_type" : "����"
]),
([      "action" : "$N�������ţ�һʽ��������ġ�����һ�������У�˫��ͬʱ����$n���ߵ���Ѩ",
        "force" : 400,
        "dodge" : 56,
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�䣬��ɫ����,һʽ���������⡹����һ˿����Χ���£�ֱ��$nӿȪ��Ѩ��",
        "force" : 400,
        "dodge" : 56,
        "damage": 220,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����������Ʊ�����֡�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷������������ơ�\n");
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
        level   = (int) me->query_skill("wuluo-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������������ơ�\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuluo-zhang/" + action;
}
