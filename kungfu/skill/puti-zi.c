// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("菩提子", ({"puti zi", "zi"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这个可是宝贝啊，吃了加100最大内力的。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
