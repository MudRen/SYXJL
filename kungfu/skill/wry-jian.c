inherit SKILL;

mapping *action = ({
([      "action" : "$N�鲽������һ�С�������衹���������Ծ������$w���������һ��������$n��$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 1000,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ���������Ƴ�������$wʹ��һʽ����Ʈ������ֱ��$n��$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 1000,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��÷�ն����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
        "force" : 170,
        "dodge" : 15,
        "damage" : 1000,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������꡹������ƽָ��һ���ǳɺ�ɨ$n��$l",
        "force" : 190,
        "dodge" : 10,
        "damage" : 1000,
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�������಻Ϣ����$w��������ԲȦ������ֱ�������಻�ϻ���$n��$l",
        "force" : 240,
        "dodge" : 10,
        "damage" : 1000,
        "lvl" : 29,
        "damage_type" : "����"
]),
([      "action" : "$N���ű任������һ�С�ϸ��ţë��������롹������$w����һ�Ž���������$n��$l",
        "force" : 280,
        "dodge" : 5,
        "damage" : 1000,
        "lvl" : 39,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�Ծ��̤�ơ������Ծ����أ�$wһ����ת�����ֹ���$n��$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 1000,
        "lvl" : 59,
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�һ�С�����ƮƮ�������⼸����ָ����Ȼ����$n��$l",
        "force" : 330,
        "dodge" : -5,
        "damage" : 1000,
        "lvl" : 79,
        "damage_type" : "����"
]),
([  "action" : "$N����š��������ǰ���ƣ�һ�С����Ƽ��¡���$w�й�ֱ�������´���$n��$l",
        "force" : 380,
        "dodge" : -5,
        "damage" : 1000,
        "lvl" : 99,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 1000)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("fyy-shengong", 1) < 100)
                return notify_fail("�����ʥ�������̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (!me) me = this_object();
        level   = (int) me->query_skill("taiji-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("��������������ŷ����꿴�ƽ�����\n");
        me->receive_damage("kee", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wry-jian/" + action;
}
