// jinwu-dao.c ���ڵ���
inherit SKILL;
mapping *action = ({
([      "action" : "$Nʹ������ѩ����������������һ�����ϵ����������ҿմ̣�����
$n�����м�֮ʱ��$w�����й�����$n��",
        "force" : 220,
        "dodge" : -5,
        "parry" : -5,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "��ѩ������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������Ƹ����������Ż��󿪣�����$w�������ã���������
ǡ��һƬ����Ю��$NƮ��$n.",
        "force" : 240,
        "dodge" : -5,
        "parry" : -5,
        "damage": 60,
        "lvl" : 9,
        "skill_name" : "�����Ƹ���",
        "damage_type" : "����",
]),
([      "action" : "$N�������裬ʹ������ͷ����ס����չ���ҫ�£�$w����һƬҫ�۰�
�⣬��һƥ��������$n,��$n�����޴롣",
        "force" : 260,
        "dodge" : -5,
        "parry" : 5,
        "damage": 70,
        "lvl" : 29,
        "skill_name" : "��ͷ�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ������δΪ�̡���ת$w������ָ�أ��������������˳��ǰ�ͣ�
���淢��������������$n���¸���",
        "force" : 280,
        "dodge" : -5,
        "parry" : 10,
        "damage": 80,
        "lvl" : 39,
        "skill_name" : "����δΪ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫���أ�һʽ��������û�ǡ������Ծ�𣬴���$n��ͷ���Ϸ�ʱ
����ֱ����׹��������ָ������$n��",
        "force" : 300,
        "dodge" : 5,
        "parry" : 15,
        "damage": 85,
        "lvl" : 59,
        "skill_name" : "������û��",
        "damage_type" : "����"
]),
([      "action" : "$N˫��������ǰ��һ�С�������ɽ�ơ�����һ�����ǰ�����������
��Ծ��$nǰʱ��������������$n����غ�Ԩͣ��������$n��ǰ��",
        "force" : 320,
        "dodge" : 10,
        "parry" : 10,
        "damage": 95,
        "lvl" : 69,
        "skill_name" : "������ɽ��",
        "damage_type" : "����"
]),
([      "action" : "$N��Ծ����һ�С���紵��ˮ������˫�־�$w���������ᵶ������
������$n��ͷ�������漤�������������졣",
        "force" : 340,
        "dodge" : -5,
        "parry" : -5,
        "damage": 105,
        "lvl" : 89,
        "skill_name" : "��紵��ˮ",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N$w����ʹ����������ҹ�������ζ����³�����$n��ȥ��գ�ۼ�
����$n��ǰ��$w�ӳ�����$n���Ȳ���",
        "force" : 360,
        "dodge" : 5,
        "parry" : 25,
        "damage": 115,
        "lvl" : 109,
        "skill_name" : "������ҹ��",
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="shenghuo-shengong"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 30)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");
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
        level   = (int) me->query_skill("jinwu-dao",1);
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
                return notify_fail("����������������ڵ���\n");
        me->receive_damage("qi", 35);
        return 1;
}
string *parry_msg = ({
        "ֻ�������ϡ�һ������$p���ˡ�\n",
        "�����������һ����$p�����ˡ�\n",
        "���Ǳ�$n������$v�ܿ���\n",
        "����$n����һ�࣬������$v�񿪡�\n",
});
string *unarmed_parry_msg = ({
        "���Ǳ�$p���ˡ�\n",
        "�����$p�����ˡ�\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
