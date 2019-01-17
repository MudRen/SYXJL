//lingwu.c ����
//write by Ronger 01/99

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skillname;
	int skill;

	if( !arg )
		return notify_fail("�����Լ�����ʲô����\n");
	if(me->query("combat_exp") < 2000000)
		return notify_fail("��ʹ�����밡�룬���Ƿ���ʲôҲ��᲻�����������黹������\n");

	if ( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");

	if ( !(skillname = me->query_skill_mapped(arg)) ) {
		if (arg == to_chinese(arg))
			return notify_fail("����û���ֹ���ɣ�\n");
	}

	if (!me->query_skill(arg,1))
		return notify_fail("����󲻻ᡸ" + to_chinese(arg) + "���ɣ�\n");

	skill = me->query_skill(arg,1);

	if ( (string)SKILL_D(arg)->type() == "knowledge" )
		return notify_fail( to_chinese(arg) + "ֻ�ܿ�ѧϰ����ߡ�\n");

	if ( (string)SKILL_D(arg)->type() == "martial"
		&& skill * skill * skill / 10 > (int)me->query("combat_exp") )
		return notify_fail("���ʵս���鲻��������ô��Ҳû�á�\n");

	if( !SKILL_D(arg)->valid_learn(me) ) return SKILL_D(arg)->valid_learn(me);

	if (skill < 150)
		return notify_fail("������Ź��򼶱�̫�ͣ��޷��Լ����򣬻���ȥ��ʦ��ѧϰ�ɡ�\n");

	if ( me->query("jing") < 20 )
		return notify_fail("���Ѿ������ˣ���Ϣһ�°ɡ�\n");

	if ( me->query("qi") < 20 )
		return notify_fail("�����������ˣ���Ϣһ�°ɡ�\n");

	if ( me->query("neili") <= 5 )
		return notify_fail("�����������ˣ���Ϣһ�°ɡ�\n");

        if ( me->query("potential") - me->query("learned_points") <= 0 )
		return notify_fail("���Ǳ�������ˡ�\n");

	write(HIY "����ϥ���£�ڤ˼���룬�ƺ���" + to_chinese(arg) + "�����������һ�㡣\n" NOR);
	me->receive_damage("jing",10);
	me->receive_damage("qi",30);
        me->add("learned_points", 1);
	me->add("neili",-5);
        me->improve_skill(arg, me->query_int()/10 * skill/4);

	return 1;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��lingwu <��������>

���ָ����������Լ�����ĳ��ܡ���Ȼ������֮ǰ������ʵ�������л�
���㹻�ľ�����֧���������ܡ�
TEXT
	);
	return 1;
}

