// thousand.c

inherit MONEY;
#include <ansi.h>
void create()
{
        set_name(HIG"一千两金票"NOR, ({"hundredthousand-cash", "hundredthousand-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "hundredthousand-cash");
                set("long", "一张面额值一千两金子的银票。\n");
		set("unit", "叠");
                set("base_value", 10000000);
		set("base_unit", "张");
		set("base_weight", 3);
	}
	set_amount(1);
}

