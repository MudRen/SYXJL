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

	set_name("玉笛", ({"yu di", "di"}));

	set("unit", "支");

	set_weight(300);

	set("long", "这是一只二尺来长的玉笛。\n");

	set("value", 10000);

	set("material", "bamboo");

	set("wield_msg", "$N大袖一挥，手中已多了一支晶莹温润的玉笛。\n");

	set("unwield_msg", "$N手中玉萧一转，眨眼间玉笛已然不见影踪。\n");



//	setup();

}



int do_play(string arg)

{

	if (!id(arg))

		return notify_fail("你要演奏什么？\n");

	message_vision("$N将玉笛放到口边，轻轻一吹，忽听得“呜呜”几个柔和的笛声飘出。")



	return 1;

}