// wineskin.c  ¾Æ´ü

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("±ù¾§ºì²è", ({"hongcha", "tea"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»±­ÏãÅçÅçµÄ±ù¾§ºì²è¡£\n");
		set("unit", "±­");
		set("value", 1000);
		set("max_liquid", 30);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
//		"type": "alcohol",
		"name": "±ù¾§ºì²è",
		"remaining": 30,
		"drunk_apply": 30,
	]));
}
