// doufu.c ¶¹¸¯

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("¶¹¸¯", ({"doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éË®ÁéÁéµÄ´ó¶¹¸¯¡£\n");
		set("unit", "¿é");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
