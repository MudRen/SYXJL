// shanghan.c �˺���

inherit ITEM;
#include <ansi.h>

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"�˺���"NOR, ({"shanghan chou", "shanghanchou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ר���˺���ҩ�������ޱȡ�\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if (!me->query_condition("ill_shanghan"))
	{
		write("��������û�е��˺������ҳ�ҩ��\n");
		return 1;
	} else {
		me->clear_condition("ill_shanghan");
		message_vision("$N����һ���˺����ɫ�������ö��ˡ�\n", me);
		me->start_busy(2);
		destruct(this_object());
		return 1;
	}
}
