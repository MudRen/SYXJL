// datengnuo-bufa.c ����Ų����
inherit SKILL;
mapping *action = ({
([      "action" : "$n����΢���Ѵܳ�������һ�㣬����ƽƽ�ɶɣ���������ȣ����
��Ӱ��ٿ������$N�����\n",
        "dodge"  : 10
]),
([      "action" : "$n���ʹ�����������б�ɶ��ϣ��紩��������Ѹ�ٷ��裬������
ȥ����������ˮ�������ޱȡ�\n",
        "dodge"  : 20
]),
([      "action" : "$nչ���Ṧ����һ���̰��Ƶ�$N����󣬲���$N������һ����һ
��������һȦ����תһȦ����$N�޴����֡�\n",
        "dodge"  : 30
]),
([      "action" : "$n˫�����������֮״��������ǰ�����˺�Ծ���ڿ���������������
����������е�����$N��ǰ�档\n",
        "dodge"  : 40
]),
([      "action" : "$n��Ȼ���ΰ����ڿ��м�����������ת�ĸ�Ȧ�ӣ���ת���ߣ����Ǹ�
ת�ۣ��������ɵ���������֮�⡣\n",
        "dodge"  : 50
]),
([      "action" : "$n�������ĵر����������ۿ���Ҫ�������������������У�$n�Ѿ��ڳ�
$N����ʽ������Χ֮�⡣\n",
        "dodge"  : 60
]),
([      "action" : "$n�ڿ�һԾ������������ʱ��������һ����棬�����ٶ�Ծ���⼸��
�������䣬Ѹ�����ף�������ѣĿ�ڡ�\n",
        "dodge"  : 70
]),
([      "action" : "$n�㲻̧��ϥ����������ٿ�غ��ƣ�������׵ض㿪��$N�Ĺ��ƣ�$nվ��
$N����֮����Ԩͣ���š�\n",
        "dodge"  : 80
])
});
mapping query_action(object me, object weapon)
{
        int zhaoshu, level;
        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("datengnuo-bufa");
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
string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;
        me = this_player();
        action = query_action(me, ob);
        return action["action"];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ�����������Ų������\n");
        me->receive_damage("qi", 30);
        return 1;
}
