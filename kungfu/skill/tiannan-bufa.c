// tiannan-bufa.c ���ϲ���

inherit SKILL;

string *dodge_msg = ({
        "$nͻȻ��ǰһ��ʹ�����������졹,����һ��,���ױܿ���$N�Ĺ�����\n",
        "$nһʽ�������ޱߡ���$Nֻ����ǰһ�Σ����Ѳ���$n����Ӱ��$n�·��Ѿ���ʧ�����ޱߵĶ����С�\n",
        "$nһ�С���ɽ���ơ����߸�Ծ�𣬿����ּ�ʹǧ��׹�����ȵ�������$N���\n",
        "$nһ��������֮ӥ��������һ����$N��һ�����˸��ա�\n",
        "ȴ��$n�������ƺ������㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        "$n����һ�С�������Ͼ��������΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ���������ܲ�����\n");
        me->receive_damage("qi", 30);
        return 1;
}
