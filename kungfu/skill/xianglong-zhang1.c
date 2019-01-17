// xianglong-zhang.c

inherit SKILL;

mapping *action = ({
([      "action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l",
        "dodge": -30,
        "parry": 10,
        "force": 1000,
        "damage": 160,
        "lvl" : 140,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l",
        "dodge": -15,
        "parry": -20,
        "force": 400,
        "damage": 90,
        "lvl" : 120,
        "damage_type": "����"
]),
([      "action": "$N����һ�С����������Ѹ���ޱȵ�����$n��$l",
        "dodge": -10,
        "parry": -10,
        "force": 200,
        "damage": 100,
        "lvl" : 130,
        "damage_type": "����"
]),
([      "action": "$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l",
        "dodge": -15,
        "parry": -10,
        "force": 300,
        "damage": 100,
        "lvl" : 30,
        "damage_type": "����"
]),
([      "action": "$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l",
        "dodge": -10,
        "parry": 10,
        "force": 900,
        "damage": 90,
        "lvl" : 40,
        "damage_type": "����"
]),
([      "action": "$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l",
        "dodge": -10,
        "parry": 20,
        "force": 400,
        "damage": 100,
        "lvl" : 10,
        "damage_type": "����"
]),
([      "action": "$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
        "dodge": 0,
        "parry": 10,
        "force": 500,
        "damage": 90,
        "lvl" : 20,
        "damage_type": "����"
]),
([      "action": "$N���һ����˫��ʹ�����𾪰��������һ�а����$n",
        "dodge": -25,
        "parry": -10,
        "force": 600,
        "damage": 150,
        "lvl" : 60,
        "damage_type": "����"
]),
([      "action": "$Nʹ������Ծ��Ԩ������$n��$l��������",
        "dodge": -20,
        "parry": -20,
        "force": 700,
        "damage": 120,
        "lvl" : 60,
        "damage_type": "����"
]),
([      "action": "$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l",
        "dodge": -10,
        "parry": 20,
        "force": 800,
        "damage": 160,
        "lvl" : 70,
        "damage_type": "����"
]),
([      "action": "$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����",
        "dodge": -20,
        "parry": 30,
        "force": 800,
        "damage": 180,
        "lvl" : 80,
        "damage_type": "����"
]),
([      "action": "$N˫������ʹ����ʱ����������$n��������",
        "dodge": -20,
        "parry": 20,
        "force": 800,
        "damage": 180,
        "lvl" : 80,
        "damage_type": "����"
]),
([      "action": "$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l",
        "dodge": -15,
        "parry": 20,
        "force": 800,
        "damage": 200,
        "lvl" : 90,
        "damage_type": "����"
]),
([      "action": "$Nʹ�����������ڡ���˫�������������$n��$l",
        "dodge": -25,
        "parry": 10,
        "force": 800,
        "damage": 150,
        "lvl" : 80,
        "damage_type": "����"
]),
([      "action": "$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l",
        "dodge": -20,
        "parry": 40,
        "force": 800,
        "damage": 250,
        "lvl" : 100,
        "damage_type": "����"
]),
([      "action": "$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ",
        "dodge": -25,
        "parry": 1,
        "force": 800,
        "damage": 280,
        "lvl" : 110,
        "damage_type": "����"
]),
([      "action": "$Nʹ��������ެ����˫���������ϻ���$n��$l",
        "dodge": -15,
        "parry": 40,
        "force": 800,
        "damage": 300,
        "lvl" : 120,
        "damage_type": "����"
]),
([      "action": "$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l",
        "dodge": -10,
        "parry": 40,
        "force": 800,
        "damage": 380,
        "lvl" : 140,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ʮ���Ʊ�����֡�\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 20)
                return notify_fail("��Ļ���������򲻹����޷�������ʮ���ơ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�������ʮ���ơ�\n");
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
                return notify_fail("�����������������ʮ���ơ�\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xianglong-zhang/" + action;
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
