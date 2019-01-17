// wineskin.c  ¾Æ´ü
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
         set_name(HIR"Ï²¾Æ"NOR, ({"xijiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
                   set("long", "Ò»Æ¿Ã©Ì¨¾Æ¡£\n");
                 set("unit", "Æ¿");
                 set("value", 5000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
                 "name": "Ã©Ì¨¾Æ",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
