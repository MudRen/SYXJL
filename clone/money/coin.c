// coin.c

inherit MONEY;
#include <ansi.h>
void create()
{
	set_name(YEL"ͭ��"NOR, ({"coin", "coins", "coin_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ����ͭ���ֵ��һ��������\n");
		set("unit", "Щ");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 1);
	}
	set_amount(1);
}
