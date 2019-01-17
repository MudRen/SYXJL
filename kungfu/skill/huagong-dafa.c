// huagong-dafa.c ������
// by QingP

inherit SKILL;

int valid_enable(string usage)
{
	return usage=="poison";
}

int valid_learn(object me)
{
	if ((int)me->query_skill("beiming-zhenqi", 1) < 100)
		return notify_fail("��ı�ڤ������������������ѧ�����󷨡�\n");

	if ((int)me->query_skill("poison", 1) < 130)
		return notify_fail("��Ļ�������������죬����ѧ�����󷨡�\n");

	if ( !me->query_skill("beiming-zhenqi",1))
		return notify_fail("�㲻��ѧ�ᱱڤ����������ѧ�����󷨣�\n");

	if ( !me->query_skill("poison",1))
		return notify_fail("�㲻��ѧ��������������ѧ�����󷨣�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������󷨱�����֡�\n");

	return 1;
}

int practice_skill(object me)
{
	object ob;
	
	if ((int)me->query_skill("beiming-zhenqi", 1) < 100)
		return notify_fail("��ı�ڤ������������������ѧ�����󷨡�\n");

	if ((int)me->query_skill("poison", 1) < 130)
		return notify_fail("��Ļ�������������죬����ѧ�����󷨡�\n");

	if ( !me->query_skill("beiming-zhenqi",1))
		return notify_fail("�㲻��ѧ�ᱱڤ����������ѧ�����󷨣�\n");

	if ( !me->query_skill("poison",1))
		return notify_fail("�㲻��ѧ��������������ѧ�����󷨣�\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������󷨡�\n");

	if (!objectp(ob = present("shenmu wangding", me)))
		return notify_fail("��û����ľ��������ô�������󷨣���\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������󷨱�����֡�\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˣ������������󷨡�\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("������������������󷨡�\n");
	if (me->query_skill("huagong-dafa", 1) < 50)
		me->receive_damage("qi", 20);
	else
		me->receive_damage("qi", 70);
	me->add("neili", -70);
	return 1;
}

void skill_improved(object me)
{
	me->add("shen", -1300);
}

string perform_action_file(string action)
{
	return __DIR__"huagong-dafa/" + action;
}