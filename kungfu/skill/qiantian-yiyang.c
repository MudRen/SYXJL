#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{       
        
        int i, l,q;        
        int t = 1, j;
       for (j = 1; j < i / 10; j++) t *= 2;        
        i = (int)me->query_skill("force", 1);       
        l = (int)me->query_skill("buddhism", 1);       
       q = (int)me->query_skill("qiantian-yiyang", 1);       

        if (!me->query("tls"))
        if (q > 20 && (int)me->query("shen") < t * 100)
        return notify_fail("���������������ɣ��������������������������\n");

        if (q > 20 && q < 150 && l < q - 10)
        return notify_fail("��ķ�ѧ��Ϊ����������ֹ������еĺ�ʤ֮���ˣ�\n");

        if (i < 20)
                 return notify_fail("��Ļ����ڹ���򻹲������޷����Ǭ��һ������\n");

        if (i > 99 && (string)me->query("gender") != "����")
                 return notify_fail("�㲻�Ǵ���֮���޷������߲��Ǭ��һ������\n");

        if ( 
           me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("guiyuan-tunafa",1)
        || me->query_skill("xixing-dafa",1)
        )
        return notify_fail("Ǭ��һ�������ɺ�а���ڹ���Ϊһ�壿\n");

        return 1;
}


int practice_skill(object me)
{
            return notify_fail("Ǭ��һ����ֻ����ѧ(learn)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"qiantian-yiyang/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIY + me->name()+"�����������̬���ꡣ" NOR,
    "start_my_msg" : "����ϥ���£���Ŀ��ʲ������Ǭ��һ���񹦣�һ�ɴ���������ʼ��������ת��\n",
    "start_other_msg" : me->name()+"��ϥ���£���Ŀ��ʲ,��̬���꣬�����ƺ���һ�������֡�\n",
    "halt_msg" : "$N˫��һ�֣�ƽ̯���أ�Ѹ��������ֹͣ������������\n",
    "end_my_msg" : "������������������һ�����죬���������ڵ�������������۾���\n",
    "end_other_msg" : "ֻ��"+me->name()+"���������۾����������ֵĽ������ȥ��\n"
          ]);
}