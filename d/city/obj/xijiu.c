// wineskin.c  �ƴ�
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
         set_name(HIR"ϲ��"NOR, ({"xijiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
                   set("long", "һƿę́�ơ�\n");
                 set("unit", "ƿ");
                 set("value", 5000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
                 "name": "ę́��",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
