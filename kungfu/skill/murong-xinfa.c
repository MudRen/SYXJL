// Ľ���ķ�
// bye jfeng
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");
        if ( me->query("gender") == "����" )
                return notify_fail("���޸����ԣ����������������������Ľ���ķ���\n");
        return 1;
}
int practice_skill(object me)
{
    return notify_fail("��Ȫ��ֻ����ѧ(learn)�����ӵȼ���\n");
}
string exert_function_file(string func)
{
    return __DIR__"murong-xinfa/" + func;
}
