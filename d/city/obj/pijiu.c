// wineskin.c  ¾Æ´ü

inherit ITEM;
inherit F_LIQUID;

void create()
{
       set_name("Æ¡¾Æ", ({"pi jiu", "pi", "jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("long", 
        "Ò»ÌýÀ¶´øÆ¡¾Æ¡£\n");
              set("unit", "Ìý");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
               "name": "Æ¡¾Æ",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
