// yihua-jiemu.c 移花接木
// by rtm 00.03

inherit SKILL;

string *parry_msg = ({
	"$N一招击在$n身上，却被$n暗运移花接木，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
        "$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
        "$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
        "$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});

string *dodge_msg = ({
	"$N一招击在$n身上，却被$n暗运移花接木，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
        "$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
        "$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
        "$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
       return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("yihua-jimu", 1);

        if ( me->query("gender") == "男性" && lvl > 99)
                return notify_fail("移花接木乃移花宫宫主所创,向来不传男子。\n");

        if ((int)me->query_skill("yihua-force", 1) < 150)
                return notify_fail("你的移花心法还不到家怎么能学移花接木呢？\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("就这么点基本内功还想学移花接木？\n");

	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("就这么点内力还想学移花接木？\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("你的基本内功火候还不够，小心走火入魔！\n");

        return 1;
}

string perform_function_file(string func)
{
        return __DIR__"yihua-jiemu/" + func;
}