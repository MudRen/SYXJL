// duanjia-jian.c �μҽ���
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһʽ���ƺ����롹������$w�ó�һ������ն��$n��$l",
        "force" : 40,
        "dodge" : 100,
        "damage": 60,
        "parry" : 100,
        "lvl" : 20,
        "skill_name" : "�ƺ�����",
        "damage_type":  "����"
]),
([      "action":"$N�粽��ǰ��ʹ��������ֱ�¡�������$w��ֱ����$n��$l��ȥ",
        "force" : 80,
        "dodge" : 150,
        "parry" : 100,
        "damage": 80,
        "lvl" : 40,
        "skill_name" : "����ֱ��",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ��ѩӿ���ء����������콣Ӱ��$w����$nȫ���Ѩ",
        "force" : 100,
        "dodge" : 140, 
        "parry" : 100,
        "damage" : 130,
        "lvl" : 50,
        "skill_name" : "ѩӿ����",
        "damage_type":  "����"
]),
([      "action":"$N��������Ծ��һʽ�����ͻ�𡹣�����ͻȻ����ת�죬$wֱ��$n��$l��ȥ",
        "force" : 100,
        "dodge" : 160,
        "parry" : 100,
        "damage": 150,
        "lvl" : 70,
        "skill_name" : "���ͻ��",
        "damage_type":  "����"
]),
([      "action":"$N����$w����һ�ͣ�һʽ��ҹ��̽������������Ϣ�ض�׼$n��$l�̳�һ��",
        "force" : 120,
        "dodge" : 100,
        "parry" : 100,
        "damage": 150,
        "lvl" : 100,
        "skill_name" : "ҹ��̽��",
        "damage_type":  "����"
]),
([      "action":"$N˫�ֽ�������$w��ֱָ��񷣬��â���ǣ�һʽ��̩ɽѹ��������׼$n��$l��ȥ",
        "force" : 150,
        "dodge" : 150, 
        "parry" : 100,        "damage": 170,
        "lvl" : 120,
        "skill_name" : "̩ɽѹ��",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ������滨������ָ��㣬һ����Ѫ��������$w�ϣ�˳������һ�£�һ�ƺ����$n��ȥ",
        "force" : 170,
        "dodge" : 100, 
        "parry" : 100,        "damage": 200,
        "lvl" : 190,
        "skill_name" : "����滨",
        "damage_type":  "����"
]),
([      "action":"$Nͻ�ĳ��������Ż���һʽ����¹��ԭ����$w����һ����ֱȡ$n������",
        "force" : 180,
        "dodge" : 100,
        "parry" : 100,
        "damage": 280,
        "lvl" : 200,
        "skill_name" : "��¹��ԭ",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="yiyang-zhi"; }


int valid_learn(object me)
{       object ob;
        if (!objectp(ob = me->query_temp("weapon"))
         || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ�����ϰ��������\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("kurong-changong", 1) < 50)
                return notify_fail("��Ŀ����������̫ǳ��\n");
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
        level   = (int) me->query_skill("duanjia-jian",1);
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
        if ((int)me->query("qi") < 50)
                return notify_fail("��������������μҽ�����\n");
        me->receive_damage("qi", 25);
        return 1;
}


string perform_action_file(string action)
{
        return "/kungfu/skill/duanjia-jian/" + action;
}

/*int practice_skill(object me)
{
        object ob;

    if( (int)me->query("qi") < 20
    ||  (int)me->query("neili") < 5 )
        return notify_fail("�����������������û�а취��ϰ�μҽ�����\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ�����ϰ��������\n");

    me->receive_damage("qi", 10);
        me->add("force", -2);
    write("�㰴����ѧ����һ��μҽ�����\n");
        return 1;
}*/

