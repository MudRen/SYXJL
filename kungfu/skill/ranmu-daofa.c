// ranmu-daofa.c ȼľ����

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w��ڣ�һ�С���ʳ������������һ�Σ�һ����$n��$l��ȥ",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 0,
        "skill_name" : "��ʳ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������Ե����˫�����أ�$wһ�ᣬƽ�л���$n��$l",
        "force" : 190,
        "dodge" : 0,
        "parry" : 10,
        "damage" : 15,
        "lvl" : 20,
        "skill_name" : "������Ե",
        "damage_type" : "����"
]),
([      "action" : "$N���΢Ц��$wָ���Լ���һ�С��һ�����������һ��Ѹ��֮������ն��$n",
        "force" : 260,
        "dodge" : -5,         
        "parry" : 10,
        "damage" : 25,
        "lvl" : 30,
        "skill_name" : "�һ�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ľ���𡹣�$w�ϴ����ޱȾ���������һ���󻡣���ֱ����$n��$l",
        "force" : 320,
        "dodge" : 5,
        "damage" : 35,
        "lvl" : 40,
        "skill_name" : "��ľ����",
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С��Ź����¡���˫�ֳ����������У�����$n���ؿ�",
        "force" : 380,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 50,
        "skill_name" : "�Ź�����",
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С��һ����ơ����������ã����ҿ�����������$n",
        "force" : 440,
        "dodge" : 15,
        "damage" : 55,
        "lvl" : 60,
        "skill_name" : "�һ�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ͨ���ؼš������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "force" : 490,
        "dodge" : 5,
        "damage" : 70,
        "lvl" : 70,
        "skill_name" : "ͨ���ؼ�",
        "damage_type" : "����"
]),
([      "action" : "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
        "force" : 550,
        "dodge" : 20,
        "damage" : 90,
        "lvl" :80,
        "skill_name" : "������Ϣ",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 80)
                return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
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
        level   = (int) me->query_skill("ranmu-daofa",1);
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
        if ((int)me->query("qi") < 50)
                return notify_fail("�������������ȼľ������\n");
        me->receive_damage("qi", 25);
        return 1;
}
