// hantian-chuixue-jian.c ���촵ѩ����

inherit SKILL;

mapping *action = ({
([      "action":"\nͻȻ֮�䣬��Ӱ���ϣ���������ѩ����$n����������ʱ�ֻص���ԭ�ء�",
        "force" : 200,
        "dodge" : 100,
        "parry": 100,
        "damage": 400,
        "lvl" : 0,
        "skill_name" : "��ӵ�к",
        "damage_type":  "����"
]),
([      "action":"\n$NͻȻ���з�һ�䣬$w�����������ʽƮ����ӯ��$n����֮�з������!",
        "force" : 300,
        "dodge" : 100,
        "parry" : 100,
        "damage": 500,
        "lvl" : 8,
        "skill_name" : "ѩ������",
        "damage_type":  "����"
]),
([      "action":"\n$N����Ʈ��������ѩ����裬�����䣬�����������Ʋ���$n�����!",
        "force" : 160,
        "dodge" : 150,
        "parry" : 150,
        "damage": 700,
        "lvl" : 15,
        "skill_name" : "ѩ���ȷ�",
        "damage_type":  "����"
]),
([      "action":"$Nһ����Ц�������Է紵��ѩ֮����$nϯ���ȥ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w��
���ݳ�!",
        "force" : 240,
        "dodge" : 200,
        "parry" : 200,
        "damage": 900,
        "lvl" : 20,
        "skill_name" : "�绨ѩ��",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ����̧��һ��������������ѩ������ֱ����£����ɵ�һ����",
        "force" : 500,
        "dodge" : 200,
        "parry" : 200,
        "damage": 1000,
        "lvl" : 20,
        "skill_name" : "��ѩ����",
        "damage_type":  "����"
]),  
([      "action":"$NһХ���죬$n��ǰ�·�ͻȻ�����������$N�����콣��һ�����$n!",
        "force" : 220,
        "dodge" : 250,
        "parry" : 250,
        "damage": 1200,
        "lvl" : 30,
        "skill_name" : "ѩӰ����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("bahuang-gong", 1) < 100)
                return notify_fail("��İ˻Ĺ����̫ǳ��\n");
        if ((int)me->query_skill("force", 1) < 40)
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");
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
        level   = (int) me->query_skill("hantian-chuixue-jian",1);
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
                return notify_fail("����������������촵ѩ������\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"hantian-chuixue-jian/" + action;
}

