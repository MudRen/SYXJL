// ������
// bye jfeng
inherit SKILL;
mapping *action = ({
([      "action" : "$Nʹһ�С������������˫�ֻ��˸���Ȧ������$n��$l",
        "force" : 50,
        "dodge" : 30,
        "damage": 35,
        "skill_name" : "�������",
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N���Ʋ�ס����ɨ������һʽ���������ࡹ��������ת����$n��ȥ",
        "force" : 100,
        "dodge" : 60,
        "damage": 105,
        "skill_name" : "��������",
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N���־���ǰ��������ǰƲ����ʹһ�С�����ſ͡�����$n��ȥ",
        "force" : 140,
        "dodge" : 100,
        "damage": 200,
        "skill_name" : "����ſ�",
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N���Ʋ�ס����ɨ������һʽ��������졹��������ת����$n��ȥ",
        "force" : 180,
        "dodge" : 150,
        "damage": 220,
        "skill_name" : "�������",
        "lvl" : 120,
        "damage_type" : "����"
]),
([      "action" : "$N�������˫�ƻ���������Ӱ����$n,������һʽ�������ȥ����",
        "force" : 100,
        "dodge" : 120,
        "damage": 250,
        "skill_name" : "�����ȥ",
        "lvl" : 220,
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="fengye-finger"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("murong-xinfa", 1) < 20)
                return notify_fail("���Ľ���ķ���򲻹����޷�ѧ�����ơ�\n");
        if((int)me->query("max_neili") < 100)
                return notify_fail("���������Ϊ�������޷�ѧ�����ơ�\n");
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
                return notify_fail("�������������\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}
