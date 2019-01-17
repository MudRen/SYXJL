// feifeng-bian.c �ɷ�޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":               "$N������ӯһת��һ�С����չ�᡹������$w��ı�ֱ������$nֱ�̹�ȥ",
        "force":                100,
        "dodge":                10,
        "damage":               100,
        "lvl" : 0,
        "skill_name" : "���չ��",
        "damage_type":  "����"
]),
([      "action":               "$N����һת��һ�С��������衹������$w���ı�ֱ��ͻȻ�͵ػ���$n̫��Ѩ",
        "force":                150,
        "dodge":                10,
        "damage":               150,
        "lvl" : 10,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action":               "$N৵�һ��$w��һ�С����񳯷������$w���Ʊ���˰ٸ����ޣ���ס��$n������Ѩ��",
        "force":                200,
        "dodge":                30,
        "damage":               200,
        "lvl" : 20,
        "skill_name" : "���񳯷�",
        "damage_type":  "����"
]),
([      "action":               "$N������ң�һ�С������ˡ�������$wͻȻ���Ʊ����һֻ���ˣ�ֱ��$nȫ�����ҪѨ",
        "force":                200,
        "dodge":                40,
        "damage":               250,
        "lvl" : 30,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":               "$N��������һ�С��ٷ���ˡ�������$w��������Ӱ���ŵ�$n��������",
        "force":                250,
        "dodge":                50,
        "damage":               300,
        "lvl" : 40,
        "skill_name" : "�ٷ����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������޷���\n");

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
        level   = (int) me->query_skill("feifeng-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("��������������ɷ�޷���\n");
        me->receive_damage("qi", 5);
        return 1;
}
