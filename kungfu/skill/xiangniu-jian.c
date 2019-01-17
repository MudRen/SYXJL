// xiangniu-jian.c (selang) ɫ�ǰｵ椽���

#include <ansi.h>
inherit SKILL;

mapping *action = ({ // 12 ��
([      "action":HIC"$Nһʽ��ɬ�项������$wָ���Լ��ؿڣ�����бб���⣬��������$n��$l��
����ȴ��$n�ظ�ץȥ��"NOR,
        "force" : 180,
                  "dodge" : 5,
                  "parry" : 5,
        "damage": 500,
        "lvl" : 0,
        "skill_name" : "ɬ��",
        "damage_type":"����"
]),
([      "action":HIR"$N����΢�࣬���ֺ�ڣ�����$wһ�С�����������Ҫ��$n�Ŀ��ӣ�"NOR,
        "force" : 230,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 500,
        "lvl" : 10,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":BLU"$N�����ǰ��$w��Ȼ���䵯�������ⱬ����һ�С����̡���$nһ�
֮�ʣ�ȹ���ѱ��������𣬴����к��"NOR,
        "force" : 280,
                  "dodge" : 10,
                  "parry" : 15,
        "damage": 550,
        "lvl" : 20,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":YEL"$N�������������ƽ�ƶ�������ָ���������ֽ����첻����һ�С����塹��
����$n"NOR,
        "force" : 360,
                  "dodge" : 10,
                  "parry" : 10,
        "damage": 600,
        "lvl" : 31,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":HIM"$N���к��䣬ʹ��һ�С���������ȫ��б�ƣ����߰���б��
��ż����Ю��һ�����ƣ�˲��$n���·���Ϊ�������飡"NOR,
        "force" : 410,
                  "dodge" : 15,
                  "parry" : 20,
        "damage": 500,
        "lvl" : 43,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":HIY"$N����$w����ƽ�̣�����������ң�һ�С����项���۹�������
�������⣬$n�������ˡ�"NOR,
        "force" : 450,
                  "dodge" : 20,
                  "parry" : 20,
        "damage": 800,
        "lvl" : 52,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":HIG"$Nһ�С�������������$w������бָ��أ����¶��ϣ�����$n��ȹ��"NOR,
        "force" : 420,
                  "dodge" : 25,
                  "parry" : 30,
        "damage": 850,
        "lvl" : 62,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":RED"$N��ǰһ����$w΢΢�����������㣬һ�С��컡����ն���ʼ��
���಻����$n����Ϊ$NΪ������������ĵ�����$N�Ļ��У�"NOR,
        "force" : 480,
                  "dodge" : 30,
                  "parry" : 30,
        "damage": 950,
        "lvl" : 74,
        "skill_name" : "���Ӳ���",
        "damage_type":"����"
]),
([      "action":MAG"$N���ֽ���һ�٣�������ʯ�⣬һ�С����������ý�����ס
$n���б�����������$n�ķ�����ȥ��"NOR,
        "force" : 460,
                  "dodge" : 40,
                  "parry" : 40,
        "damage": 1000,
        "lvl" : 85,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":HIB"$N����ؽ�������б����һ�С�ѩ�¡�������Ӱ����ֱк������
��ס$n�Ϸ�"NOR,
        "force" : 540,
                  "dodge" : 35,
                  "parry" : 35,
        "damage": 1050,
        "lvl" : 95,
        "skill_name" : "ѩ��",
        "damage_type":"����"
]),
([      "action":HIC"$Nһʽ����������$N���н������ţ�����Ӱ��ɫ���Ե���$n��ȥ��"NOR,
        "force" : 500,
                  "dodge" : 40,
                  "parry" : 45,
        "damage": 115,
        "lvl" : 107,
        "skill_name" : "����",
        "damage_type":"����"
]),
([      "action":HIW"$N�ڿն���ͻȻʹ��һ�С���ս����������Ϣ�ؼ���$n�ı�����ȥ"NOR,
        "force" : 550,
                  "dodge" : 50,
                  "parry" : 55,
        "damage": 600,
        "lvl" : 120,
        "skill_name" : "��ս",
        "damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

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
        level   = (int) me->query_skill("xiangniu-jian",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"xiangniu-jian/" + action;
}

