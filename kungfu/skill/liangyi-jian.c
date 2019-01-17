// liangyi-jian.c (kunlun) �����������ǽ���

#include <ansi.h>
inherit SKILL;

mapping *action = ({ // 12 ��
([      "action":"$Nһʽ��˳ˮ���ۡ�������$wָ���Լ��ؿڣ�����бб���⣬��������$n��$l",
        "force" : 180,
                  "dodge" : 5,
                  "parry" : 5,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "˳ˮ����",
        "damage_type":"����"
]),
([      "action":HIR"$N����΢�࣬���ֺ�ڣ�����$wһ�С���ɨǧ������ֱ��$n�������ȥ"NOR,
        "force" : 230,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 45,
        "lvl" : 10,
        "skill_name" : "��ɨǧ��",
        "damage_type":"����"
]),
([      "action":BLU"$N�����ǰ��$w��Ȼ���䵯�������ⱬ����һ�С��ͱڶ��ơ����͵ش�
��$n���ؿ�"NOR,
        "force" : 280,
                  "dodge" : 10,
                  "parry" : 15,
        "damage": 55,
        "lvl" : 20,
        "skill_name" : "�ͱڶ���",
        "damage_type":"����"
]),
([      "action":YEL"$N�������������ƽ�ƶ�������ָ���������ֽ����첻����һ�С�����ָ·����
����$n"NOR,
        "force" : 360,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 60,
        "lvl" : 31,
        "skill_name" : "����ָ·",
        "damage_type":"����"
]),
([      "action":HIM"$N���к��䣬ʹ��һ�С����ɻ�����ȫ��б�ƣ����߰���б��
��ż����Ю��һ�����ƣ����˼���׽��"NOR,
        "force" : 410,
                  "dodge" : 15,
                  "parry" : 20,
        "damage": 50,
        "lvl" : 43,
        "skill_name" : "���ɻ�",
        "damage_type":"����"
]),
([      "action":HIY"$N����$w����ƽ�̣�����������ң�һ�С���Įƽɳ��������$n"NOR,
        "force" : 450,
                  "dodge" : 20,
                  "parry" : 20,
        "damage": 80,
        "lvl" : 52,
        "skill_name" : "��Įƽɳ",
        "damage_type":"����"
]),
([      "action":"$Nһ�С�ľҶ������������$w������бָ��أ����¶��ϣ�����$n��$l",
        "force" : 420,
                  "dodge" : 25,
                  "parry" : 30,
        "damage": 85,
        "lvl" : 62,
        "skill_name" : "ľҶ����",
        "damage_type":"����"
]),
([      "action":RED"$N��ǰһ����$w΢΢�����������㣬һ�С����Ӳ��ߡ����ն���ʼ��
���಻������$n"NOR,
        "force" : 480,
                  "dodge" : 30,
                  "parry" : 30,
        "damage": 95,
        "lvl" : 74,
        "skill_name" : "���Ӳ���",
        "damage_type":"����"
]),
([      "action":MAG"$N���ֽ���һ�٣�������ʯ�⣬һ�С��������ơ����ý�����ס
$n���б�����$wֱָ$n���ʺ�"NOR,
        "force" : 460,
                  "dodge" : 40,
                  "parry" : 40,
        "damage": 100,
        "lvl" : 85,
        "skill_name" : "��������",
        "damage_type":"����"
]),
([      "action":"$N����ؽ�������б����һ�С����ɷ��١�������Ӱ����ֱк������
��ס$n�Ϸ�",
        "force" : 540,
                  "dodge" : 35,
                  "parry" : 35,
        "damage": 105,
        "lvl" : 95,
        "skill_name" : "���ɷ���",
        "damage_type":"����"
]),
([      "action":HIB"$Nһʽ��ѩӵ���š���$N���н������ţ�һ����������������$n"NOR,
        "force" : 500,
                  "dodge" : 40,
                  "parry" : 45,
        "damage": 115,
        "lvl" : 107,
        "skill_name" : "ѩӵ����",
        "damage_type":"����"
]),
([      "action":HIW"$N�ڿն���ͻȻʹ��һ�С�������ɫ����������Ϣ�ؼ���$n�ı�����ȥ"NOR,
        "force" : 550,
                  "dodge" : 50,
                  "parry" : 55,
        "damage": 125,
        "lvl" : 120,
        "skill_name" : "������ɫ",
        "damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        int na, nl;
        na = (int)me->query_skill("art", 1);
        nl = (int)me->query_skill("liangyi-jian", 1);

        if (me->query("family/master_name") == "�����" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("�����黭�����书���أ���Ȼ���޷�������������������ǽ�����\n");
        }

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if (me->query_skill_mapped("force") != "xuantian-wuji")
                return notify_fail("��ϰ���ǽ������������޼�����ϡ�\n");
        if ((int)me->query_skill("xuantian-wuji", 1) < 20)
                return notify_fail("��������޼������̫ǳ��\n");
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
        level   = (int) me->query_skill("liangyi-jian",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        int na, nl;
        int lvl = me->query_skill("liangyi-jian", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        na = (int)me->query_skill("art", 1);
        nl = (int)me->query_skill("liangyi-jian", 1);

        if (me->query("family/master_name") == "�����" )
        {
                if ( na<120 && na<=nl )
                return notify_fail("�����黭�����书���أ���Ȼ���޷�������������������ǽ�����\n");
        }

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
         if ((int)me->query("qi") < 50)
                return notify_fail("����������������ǽ�����\n");
         me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liangyi-jian/" + action;
}

