inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIR"��"NOR"��"HIC"��"NOR"�"NOR, ({"chan"}));
	set("unit", "ֻ");
	set("value", 40000);
	set("long", "����һǧ���ѵ�һ�����쾦���, ͨ��͸��,
Ω�۳ʳ�ɫ, �ܽ�ٶ���\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        message_vision(HIG"$N����һֻ�쾦��󸣬ֻ��һ�����������ķΣ�
                       ��ʱ��̨һƬ������������ˬ��\n" NOR, me);
        set_temp("nopoison", 3);
	destruct(this_object());
	return 1;
}
