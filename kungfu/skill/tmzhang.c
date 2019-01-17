#include <ansi.h>



inherit SKILL;



mapping *action = ({

([      "action": "$N��׼��϶������һ����һ��ӡ��$n�������Ŀ�Ѩ��",

        "dodge": 30,

        "force": 160,

        "damage_type": "����"

]),

([      "action": "$N�˾���˫��֮�ϣ�����ǧ��޸�������$n���š�",

        "dodge": 10,

        "force": 160,

        "damage_type": "����"

]),

([      "action": "$Nʩչ�����ó��������Σ��ĵ��������������������$n��$l",

        "dodge": 20,

        "force": 150,

        "damage_type": "����"

]),

([      "action": "$N��Ӱһ�����û����ĸ����Σ����ƴ���������������$nȫ��",

        "dodge": 30,

        "force": 200,

        "damage_type": "����"

]),

([      "action": "$N�͵��ڿն����ڰ�ջû��ɰ˵����Σ��ƾ�����ǵذ�ĳ�$n�Ƕ����¡�",

        "dodge": 40,

        "force": 300,

        "damage_type": "����"

]),

});



int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }



mapping query_action(object me)

{

        if (random(me->query_skill("unarmed")) > 60 &&

            me->query_skill("force") > 50 &&

            me->query("neili") > 100 ) {

                me->add("neili", -100);

                return ([

                "action": HIY"ֻ��$N�վ�ȫ����ȫ����������˫�ƺ��Ⱪ�֣�һ��"

                          "���˵���������$n����ǰ"NOR,

                "force": 600,

                "damage_type": "����"]);

        }

        return action[random(sizeof(action))];

}



int valid_learn(object me)

{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

                return notify_fail("����ħ�Ʊ�����֡�\n");

        if ((int)me->query_skill("tmdafa", 1) < 10)

                return notify_fail("�����ħ�󷨻�򲻹����޷�����ħ�ơ�\n");

        if ((int)me->query("max_neili") < 60)

                return notify_fail("�������̫�����޷�����ħ��");

        return 1;

}





int practice_skill(object me)

{

        if ((int)me->query("qi") < 30)

                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 8)

                return notify_fail("���������������ħ�ơ�\n");

        if (me->query_skill("tmzhang", 1) < 50)

                me->receive_damage("qi", 20);

        else

                me->receive_damage("qi", 30);

        me->add("neili", -5);

        return 1;

}

string perform_action_file(string action)
{
        return __DIR__"tmzhang/" + action;
}

