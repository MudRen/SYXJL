// tiannan-bufa.c 天南步法

inherit SKILL;

string *dodge_msg = ({
        "$n突然跨前一步使出「醉望南天」,身形一闪,轻易避开了$N的攻击。\n",
        "$n一式「洱海无边」，$N只觉眼前一晃，早已不见$n的踪影，$n仿佛已经消失在了无边的洱海中。\n",
        "$n一招「苍山入云」，高高跃起，空中又急使千斤坠，稳稳的落在了$N身后。\n",
        "$n一个「翔天之鹰」，身形一闪，$N这一招扑了个空。\n",
        "却见$n「深入云海」，足不点地，往旁窜开数尺，躲了开去。\n",
        "$n身形一招「明月无暇」，身形微晃，有惊无险地避开了$N这一招。\n"
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
                return notify_fail("你的体力太差了，不能练蟾蜍步法。\n");
        me->receive_damage("qi", 30);
        return 1;
}
