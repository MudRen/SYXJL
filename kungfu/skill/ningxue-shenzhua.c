// ningxue-shenzhua.c ��Ѫ��ץ

inherit SKILL;

mapping *action = ({
([      "action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ��������̽צ��ץ��$n��$l",
        "dodge": 300,
        "parry": 500,
        "force": 400,
        "damage": 500,
        "lvl" : 300,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�־Ӹ�����һ�С���ӥ���á�ץ��$n��$l",
        "dodge": 350,
        "parry": 480,
        "force": 450,
        "damage": 600,
        "lvl" : 350,
        "damage_type": "����"
]),
([      "action": "$N����һ�С��ڻ����ġ���Ѹ���ޱȵ�ץ��$n��$l",
        "dodge": 500,
        "parry": 500,
        "force": 600,
        "damage": 800,
        "lvl" : 400,
        "damage_type": "����"
]),
([      "action": "$N˫��ʩ��һ�С�̩ɽѹ�������������ŷ���ץ��$n��$l",
        "dodge": 800,
        "parry": 800,
        "force": 800,
        "damage": 1000,
        "lvl" : 500,
        "damage_type": "����"
]),
([      "action": "$N���־۳ɻ�צ״������һ�С���Ѫ��ץ������ץ��$n��$l",
        "dodge": -10,
        "parry": 50,
        "force": 800,
        "damage": 600,
        "lvl" : 40,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry" ||  usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ѫ��ץ������֡�\n");
        if ((int)me->query_skill("honghua-shengong", 1) < 20)
                return notify_fail("��ĺ컨�񹦻�򲻹����޷�����Ѫ��ץ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����Ѫ��ץ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("���������������Ѫ��ץ��\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"ningxue-shenzhua/" + action;
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

