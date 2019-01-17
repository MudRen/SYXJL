// yunu-jiafa ��Ů���Ľ�
// Modify By csy 98/12
inherit SKILL;

mapping *action = ({
([      "action" : "$N���߶��£�һʽ������б�����������»�������ֱ��$nͷ��",
        "force" : 130,
        "dodge" : 50,
        "damage" : 40,
        "parry" : 15,
        "lvl" : 0,
        "skill_name" : "����б��",
        "damage_type" : "����"
]),
([      "action" : "$N̤ǰ����������ңָ������$wʹһʽ���˼����ġ�ֱ��$n������",
        "force" : 155,
        "dodge" : 45,
        "damage" : 65,
        "parry" : 20,
        "lvl" : 10,
        "skill_name" : "�˼�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ǰ���¡���$w�������ʻ���չ���У����ػ���",
        "force" : 200,
        "dodge" : 40,
        "damage" : 80,
        "parry" : 10,
        "lvl" : 20,
        "skill_name" : "��ǰ����",
        "damage_type" : "����"
]),
([      "action" : "$N�����Ϸ�����Ȼָ���Լ���ӣ����һ�С�����С�á��������ٱ�����
һ�㣬��ɨ$n��$l",
        "force" : 235,
        "dodge" : 35,
        "damage" : 85,
        "parry" : 15,
        "lvl" : 30,
        "skill_name" : "����С��",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�������ٰ����$w�Ժ���ǰ��������״���漴�����й���ƽ��$n��$l",
        "force" : 260,
        "dodge" : 30,
        "damage" : 90,
        "parry" : 5,
        "lvl" : 40,
        "skill_name" : "���ٰ���",
        "damage_type" : "����"
]),
([      "action" : "$N�ὣб����΢΢������һ�С��ʱʻ�ü��������������ױ֮״��һ�����ߣ�
$wȴ˿��δ��ͣ��������$n��$l",
        "force" : 275,
        "dodge" : 25,
        "damage" : 95,
        "parry" : 20,
        "lvl" : 50,
        "skill_name" : "�ʱʻ�ü",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��ٰ���ü����˫�����ս������ٽ�������ֱ��$n�ĵ���",
        "force" : 290,
        "dodge" : 20,
        "damage" : 100,
        "parry" : 25,
        "lvl" : 70,
        "skill_name" : "�ٰ���ü",
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����������һ�С�ľ�����䡹�������ͦ�������򱳺�̳���ֱ��$n
���ؿ�",
        "force" : 305,
        "dodge" : 15,
        "damage" : 105,
        "parry" : 20,
        "lvl" : 90,
        "skill_name" : "ľ������",
        "damage_type" : "����"
]),
([  "action" : "$Nһ�С��ֻ���������$w����ʵ�ң�����ʵ����ʵĪ�磬����$n�ĺ�ͷ",
        "force" : 350,
        "dodge" : 10,
        "damage" : 110,
        "parry" : 15,
        "lvl" : 110,
        "skill_name" : "�ֻ�����",
        "damage_type" : "����"
]),
([  "action" : "$N�۽Ǿ���Ц�⣬üĿ���飬һ�С���Ӱ���桹���������Ӱ��$n����������
ƮƮ�н����������ԣ�",
        "force" : 375,
        "dodge" : 15,
        "damage" : 120,
        "parry" : 20,
        "lvl" : 130,
        "skill_name" : "��Ӱ����",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("�����Ů�ľ�����������\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yunu-jianfa",1);
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
           if ((int)me->query("qi") < 40)
                return notify_fail("���������������Ů���Ľ���\n");
        if((int)me->query("neili") < 20)
                return notify_fail("���������������Ů���Ľ���\n");
          me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunu-jianfa/" + action;
}
