// duanshi-shenfa.c 段氏身法

inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「旱地拔葱」，前后脚脚尖微微加力，身体猛的向上窜起两丈高。\n",
	"dodge"  : 10
]),
([	"action" : "$n一式「雨燕归巢」，身体在空中猛的一顿，双臂平伸，全身贴地平飞，顿时闪过了$N的凌厉攻势。\n",
	"dodge"  : 20
]),
([	"action" : "$n一式「破土而出」，双掌一格，身体猛的一个旋转，就势转到了$N的身后。\n",
	"dodge"  : 30
]),
([	"action" : "$n一式「无中生有」，一眨眼间，四面八方全是$n的身影，齐向$N扑去，令$N手无足措。\n",
	"dodge"  : 40
]),
([	"action" : "$n一式「乘风而去」，身体微倾，拔地而起，在半空中一个挪移，越过了$N的头顶，落到离$N几丈远的后方。\n",
	"dodge"  : 50
]),
([	"action" : "$n一式「鲧化大鹏」，两臂鹏举如翼，在剌剌风声中，滑到了$N的侧后方。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「青云直上」，双脚点地，全身化为一道黑影，绕着$N几个盘旋，身体蹦起十丈高。\n",
	"dodge"  : 70
]),
([	"action" : "$n一式「凤翔九天」，真气从涌泉穴狂泻而出，向天上腾起，足不沾地，连着几个翻腾，躲过了$N的一抡猛攻。\n",
	"dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("duanshi-shenfa");

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
		return notify_fail("你的体力太差了，不能练段氏身法。\n");
	me->receive_damage("qi", 30);
	return 1;
}
