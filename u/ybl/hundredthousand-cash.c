// thousand.c

inherit MONEY;
#include <ansi.h>
void create()
{
        set_name(HIG"һǧ����Ʊ"NOR, ({"hundredthousand-cash", "hundredthousand-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "hundredthousand-cash");
                set("long", "һ�����ֵһǧ�����ӵ���Ʊ��\n");
		set("unit", "��");
                set("base_value", 10000000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

