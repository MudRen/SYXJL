// sucai.c �ز�

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ز�", ({"sucai", "cai"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ƽ���������زˡ�\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
