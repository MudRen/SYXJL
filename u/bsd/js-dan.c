// zengsui-dan.c
// ronger 98/07/19
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG"���굤"NOR, ({"jiansui dan" , "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ż��굤�����԰��˱�С��\n");
		}
	setup();
}
int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	else{
                me->add("mud_age",-86400*30);
                me->add("age", -30);
         	me->save();

	message_vision(HIG "$N����һ�ż��굤��ֻ��������ûʲô��Ӧ���ѵ��ϵ�����\n" NOR, me);
		destruct(this_object());
		return 1;
       } 
}
