// hundred.c
//by aeolus just for fun
inherit MONEY;
inherit F_FOOD;
#include <ansi.h>
void create()
{
	set_name(HIY"一百两金票"NOR, ({"hundred-cash", "hundred-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "hundred-cash");
		set("long", "一张面额值一百两金子的金票。\n");
		set("unit", "叠");
		set("base_value", 1000000);
		set("base_unit", "张");
		set("base_weight", 3);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
	set_amount(1);
}
