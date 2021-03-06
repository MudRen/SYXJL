// 星移步
// bye jfeng
#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
HIY"$n一个「灵龟轻戏水」，跃起数尺，躲过了$N这一招。"NOR,
YEL"$n身形向后一纵，使出一招「玉兔浮落尘」，避过了$N的攻击。"NOR,
HIW"$n使出「锦鲤跃龙门」，恰好躲过了$N的攻势。"NOR,
HIY"$n一招「人随风而逝」，姿态美妙地躲了开去。"NOR,
});
int valid_enable(string usage)
{
        return (usage == "dodge") || (usage == "move");
}
int valid_learn(object me) { return 1; }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("你的体力太差了，不能练星移步。\n");
        if (me->query_skill("xingyi-bu", 1) < 50)
                   me->receive_damage("qi", 10);
        else if (me->query_skill("xingyi-bu", 1) < 100)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);
        return 1;
}
