#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
//      "$nһ�������ѵ�ˮ���������$N��һ�С�\n",
//      "$n�������һ�ݣ�ʹ��һ�С�ϸ���ɷ��ơ����ܹ���$N�Ĺ�����\n",
//      "$nʹ�����黳���ȡ���ǡ�ö����$N�Ĺ��ơ�\n"
       HIB "����$n����Ʈ��������һ�ݣ�һ��һ�䣬�������,���ѱܿ���\n"NOR,
       HIM "$n������ת����̤ �����á�ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n"NOR,
       HIG "����$n����һ�ã�Ծǰ���ᡢ�������,$N��һ�����˸��ա�\n"NOR,
       HIW "ȴ��$n�㲻��أ�һʽ�����������������Դܿ����ߣ����˿�ȥ��\n"NOR,
         HIY "$n����΢�Σ�����Ѹ����Ʈ������,�о����յرܿ���$N��һ�С�\n"NOR
});

int valid_enable(string usage) 
{ 
        return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb){
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ��������貨΢����\n");
        me->receive_damage("qi", 30);
        return 1;
}

