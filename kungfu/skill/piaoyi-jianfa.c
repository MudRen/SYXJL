// Ʈ�ݽ���
// bye jfeng
inherit SKILL;
mapping *action = ({
([      "name":   "���ʱ�ѱ�����",
        "action" : "$N����$w�ᵯ,ʹ������Ʈ�ݽ���������ʽ�����ʱ�ѱ����ѡ�����Ȼ����$n",
        "force" : 30,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "�ƺ�Զ�ϰ��Ƽ�",
        "action" : "$N��Хһ�����ḧ���е�$w,ɲ�Ǽ���������һƬ������һʽ[�ƺ�Զ�ϰ��Ƽ�]����$n������",
        "force" : 50,
        "dodge" : 40,
        "damage" : 60,
        "lvl" : 1,
        "damage_type" : "����"
]),
([      "name":   "�ޱ���ľ������",
        "action" : "$N΢һ��һ��������ɫ����ޱ����£����е�$wһ�����������⣬������һʽ[�ޱ���ľ������]",
        "force" : 70,
        "dodge" : 60,
        "damage" : 80,
        "lvl" : 2,
        "damage_type" : "����"
]),
([      "name":   "����ǧ�ؿ�����",
        "action" : "$N��̤һ������̤һ��������$wʹ��һ�С�����ǧ�ؿ����ơ��������������ѽ�$n����",
        "force" : 90,
        "dodge" : 30,
        "damage" : 150,
        "lvl" : 3,
        "damage_type" : "����"
]),
([      "name":   "��ҹ˼��������",
        "action" : "$N������Թ,��ӳ������·�����Ҳ�����˸У�������һʽ[��ҹ˼��������],��������Ĵ���$n",
        "force" : 100,
        "dodge" : 70,
        "damage" : 180,
        "lvl" : 4,
        "damage_type" : "����"
]),
([      "name":   "�����ѹ�����ɽ",
        "action" : "$N����ĵ��𣬰���������$wһ����һʽ[�����ѹ�����ɽ]��������$n",
        "force" : 110,
        "dodge" : 100,
        "damage" : 200,
        "lvl" : 5,
        "damage_type" : "����"
]),
([      "name":   "�һ�����Ц����",
        "action" : "$N���΢Ц��ʹ���Ľ�����Ȼ��һʽ[�һ�����Ц����]���εĴ���$n",
        "force" : 130,
        "dodge" : 120,
        "damage" : 250,
        "lvl" : 6,
        "damage_type" : "����"
]),
([      "name":   "Ī��ǰ·��֪��",
        "action" : "$N�����ɫ����̾һ��������󿪴�ϣ�ʹ��Ʈ�ݽ�����[Ī��ǰ·��֪��]������$n",
        "force" : 150,
        "dodge" : 150,
        "damage" : 300,
        "lvl" : 7,
        "damage_type" : "����"
]),
});
int valid_enable(string usage){return (usage== "sword") || (usage== "parry");}
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("�����������ѧƮ�ݽ�����\n");
        if ((int)me->query_skill("murong-xinfa", 1) < 50)
                return notify_fail("���Ľ���ķ����̫ǳ��\n");
        if ((int)me->query_skill("sword", 1) < 50)
                return notify_fail("��Ļ����������̫ǳ��\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�������������Ʈ�ݽ�����\n");
        me->receive_damage("qi", 40);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"piaoyi-jianfa/" + action;
}
