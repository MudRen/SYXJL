// ��������
#include <ansi.h>;

inherit SKILL;

string  *msg = ({
"$N����ƽƽ�̳�һ����ʵ���Ǻ����κα仯����ȴ�к��֮����$nֻ��
һ�ɴ�����$wֱ������",
"$N���Ծ�����潣�𣬽�������֮����������һ������$n�������ڽ���֮��",
"$N��̾һ�������ֺ���һ��������ָ��$n��������˿���仯��ȴ���ý�
�����裬����ƽ�����̺����б仯������ʤ����",
"$NѸ������һ�����˽�֮�죬������˼���޷��ֱ潣·ȥ����˳�̣��������
�����������޲��ǽ��������ţ����淵�ӹ��棬ȴ�Ѳ��ٴ��κ�����",
"$N���׳�Х������Ʊ�ã������������һ��ƽָ������������$n��
�������$nֻ�������κ���֮��", 
"$N����$w��������ɽ������ͺ�һ�������ǽ�������� [ ����ʽ ]����
�����ǽ�Ӱ������ǧ��������ֻ��$n����ζ�",
"$N����ʮ�ལ��һʱѸ�������ǻ��գ�һʱ���سٻ��������޼���Ѱ��ƽ����
���ַ�˼����", 
"$nȴ��$N������磬�������磬�޿ɵ��棬�����и���$N�������纣��һ
�㣬һ��һ������ӿ�������Ӳ�����������ǿ",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}
mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+1)*40,
                "damage_type":random(2)?"����":"����",
                "dodge": random(10)-5,
                "force":300+random(50),
        ]);
}

int practice_skill(object me)
{    
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query("qi") < 40)
                return notify_fail("�����������������������\n");
        me->receive_damage("qi", 30);
        me->add("neili", -15);
        return 1;        
}

int valid_learn(object me)
{
       int skill = me->query_skill("xuantie-jianfa", 1);
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("�������������\n");
       if ((int)me->query_skill("yunu-xinjing", 1) < (skill-50))
               return notify_fail("�����Ů�ľ����̫ǳ��\n");      
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-jianfa/" + action;
}

