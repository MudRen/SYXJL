// chuixue-jian.c ���촵ѩ����
:// ghost 31/5/2000

inherit SKILL;


mapping *action = ({
([      "action":"$ņ��һ����������$N����ֱ����£����г�������$n�ľ�����",
        "force" : 100,
        "dodge" : 100,
        "damage": 100,
        "lvl" : 0,
        "skill_name" : "�콵��ѩ",
        "damage_type":  "����"
]),
([      "action":"$ņ��һ��������������ѩ������ֱ����£����ɵ�һ����",
        "force" : 150,
        "dodge" : 150,
         "damage": 150,
        "lvl" : 0,
        "skill_name" : "ѩ������",
        "damage_type":  "����"
]),
([      "action":"$ņ��һ���������ÿ�籩��������ѩ������$n�����ɵ�һ����",
        "force" : 200,
        "dodge" : 200,
        "damage": 200,
        "lvl" : 25,
        "skill_name" : "ѩ���ַ�",
        "damage_type":  "����"
]),
([      "action":"$ņ��һ���������÷紵ѩ����Ľ�����$nϮ�������ɵ�һ����",
        "force" : 250,
        "dodge" : 250,
        "damage": 250,
        "lvl" : 5,
        "skill_name" : "����ѩ",
        "damage_type":  "����"
]),
([      "action":"$ņ��һ�������������춼��$N��Ӱ�ӣ����ɵ�һ����",
        "force" : 500,
        "dodge" : 500,
        "damage": 500,
        "lvl" : 10,
        "skill_name" : "ѩӰ����",
        "damage_type":  "����"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry"; 
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
        level   = (int) me->query_skill("chuixue-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


