// duanshi-shenfa.c ������

inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ�����ذδС���ǰ��Žż�΢΢�����������͵����ϴ������ɸߡ�\n",
	"dodge"  : 10
]),
([	"action" : "$nһʽ������鳲���������ڿ����͵�һ�٣�˫��ƽ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�\n",
	"dodge"  : 20
]),
([	"action" : "$nһʽ��������������˫��һ�������͵�һ����ת������ת����$N�����\n",
	"dodge"  : 30
]),
([	"action" : "$nһʽ���������С���һգ�ۼ䣬����˷�ȫ��$n����Ӱ������$N��ȥ����$N������롣\n",
	"dodge"  : 40
]),
([	"action" : "$nһʽ���˷��ȥ��������΢�㣬�εض����ڰ����һ��Ų�ƣ�Խ����$N��ͷ�����䵽��$N����Զ�ĺ󷽡�\n",
	"dodge"  : 50
]),
([	"action" : "$nһʽ���绯�������������������������ݷ����У�������$N�Ĳ�󷽡�\n",
	"dodge"  : 60
]),
([	"action" : "$nһʽ������ֱ�ϡ���˫�ŵ�أ�ȫ��Ϊһ����Ӱ������$N�����������������ʮ�ɸߡ�\n",
	"dodge"  : 70
]),
([	"action" : "$nһʽ��������졹��������ӿȪѨ��к�����������������㲻մ�أ����ż������ڣ������$N��һ���͹���\n",
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
		return notify_fail("�������̫���ˣ���������������\n");
	me->receive_damage("qi", 30);
	return 1;
}
