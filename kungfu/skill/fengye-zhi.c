// ��Ҷָ
// bye jfeng
inherit SKILL;
mapping *action = ({
([      "action" : "$N΢̧�ұۣ���ָ�������ֱ仯��һʽ��Цָ���ա�����$n��$l",
        "force" : 60,
        "dodge" : 30,
        "lvl" : 0,
        "damage": 80,
        "skill_name" : "Цָ����",
        "damage_type" : "����"
]),
([      "action" : "$N�����̧��һʽ����÷���š�����ָ������ָ��$n����ǰ",
        "force" : 90,
        "dodge" : 60,
        "lvl" : 1,
        "damage": 100,
        "skill_name" : "��÷����",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ����������������ָ�ų����������������Ƶ���$n��$l",
        "force" : 120,
        "dodge" : 100,
        "lvl" : 2,
        "damage": 130,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ����ɳ��Ӱ������ָ���㣬ָ�����һ�����������$n��$l",
        "force" : 150,
        "dodge" : 120,
        "lvl" : 3,
        "damage": 170,
        "skill_name" : "��ɳ��Ӱ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�����´��硹����ָ�뷢���������󴺷�㴩��$n��$l",
        "force" : 180,
        "dodge" : 150,
        "lvl" : 4,
        "damage": 200,
        "skill_name" : "���´���",
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="feiyan-zhang"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ҷָ������֡�\n");
        if ((int)me->query_skill("murong-xinfa", 1) < 50)
                return notify_fail("���Ľ���ķ���򲻹����޷�ѧ��Ҷָ��\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷�����Ҷָ��\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�������������Ҷָ��\n");
        me->receive_damage("qi", 30);
        me->add("neili", -20);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"fengye-zhi/" + action;
}
