// flute2.c

// by QingP



#include <ansi.h>

#include <weapon.h>



inherit SWORD;



int do_play();



void init()

{

	add_action("do_play", "play");

}



void create()

{

	set_name("���", ({"yu di", "di"}));

	set("unit", "֧");

	set_weight(300);

	set("long", "����һֻ������������ѡ�\n");

	set("value", 10000);

	set("material", "bamboo");

	set("wield_msg", "$N����һ�ӣ������Ѷ���һ֧��Ө�������ѡ�\n");

	set("unwield_msg", "$N��������һת��գ�ۼ������Ȼ����Ӱ�١�\n");



//	setup();

}



int do_play(string arg)

{

	if (!id(arg))

		return notify_fail("��Ҫ����ʲô��\n");

	message_vision("$N����ѷŵ��ڱߣ�����һ���������á����ء�������͵ĵ���Ʈ����")



	return 1;

}