// box.c   电脑

#include <ansi.h>

inherit ITEM;

void create()
{
          set_name(HIY"电脑"NOR,({ "personal computer", "computer"}) );
	set_weight(3000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "台");
              set("long","一台 286级的电脑，这是蹦蹦平常使用的东东。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

void init()
{
           add_action("do_off","off");
           add_action("do_on","on");
}

