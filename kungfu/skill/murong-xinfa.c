// 慕容心法
// bye jfeng
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候还不够。\n");
        if ( me->query("gender") == "无性" )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的慕容心法。\n");
        return 1;
}
int practice_skill(object me)
{
    return notify_fail("清泉神功只能用学(learn)来增加等级。\n");
}
string exert_function_file(string func)
{
    return __DIR__"murong-xinfa/" + func;
}
