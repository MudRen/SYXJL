// qingyunwu.c ������

inherit SKILL;

mapping *action = ({
([      "action" : "$n����������裬��������б���벽��ǡ�������������С��������塹��Ҫּ�����˿�����\n",
    "dodge"  : 10
]),
([      "action" : "$nʹ���������ѩ������бб���˼������ƺ������·���ȴ�ڼ䲻�ݻ��Ŀ�϶�ж����$N�Ĺ��ơ�\n",
        "dodge"  : 20
]),
([      "action" : "$N����ʽ�������԰�$nΧס����֪���ģ�$nһʽ�����Ʊ��¡���������Ȱ�Ŀ����Ȧ��\n",
        "dodge"  : 30
]),
([      "action" : "$nһʽ���������ҡ���հ֮��ǰ�������ں�$N��ʽ������$n���Ӽ��������֮�\n",
        "dodge"  : 40
]),
([      "action" : "$n����������ͻȻת��ʹ���ˡ������ϡ���$N�ӽ����ƣ����޷�����$nһƬ�½ǡ�\n",
        "dodge"  : 50
]),
([      "action" : "$n���һ����ʹ����է������������������̤��������̤ʵ֮ʱ�����������������ϡ�\n",
        "dodge"  : 60
]),
([      "action" : "$nһʽ��Ʈ�����񡹣�����б�����������ȼá���������δ�á������ü��������۵�$N�����\n",
        "dodge"  : 70
]),
([      "action" : "$nһʽ����Ѹ���ɡ����ƺ��Թ��Ե�̤����������ᣬÿһ����̤�ڱ������벻�������ڡ�\n",
        "dodge"  : 80
])
});

mapping query_action(object me)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("qingyunwu");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(object me)
{
        mapping action;

        action = query_action(me);

        return action["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ������������衣\n");
        me->receive_damage("qi", 30);
        return 1;
}

