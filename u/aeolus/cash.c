// hundred.c
//by aeolus just for fun
inherit MONEY;
inherit F_FOOD;
#include <ansi.h>
void create()
{
	set_name(HIY"һ������Ʊ"NOR, ({"hundred-cash", "hundred-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "hundred-cash");
		set("long", "һ�����ֵһ�������ӵĽ�Ʊ��\n");
		set("unit", "��");
		set("base_value", 1000000);
		set("base_unit", "��");
		set("base_weight", 3);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
	set_amount(1);
}
