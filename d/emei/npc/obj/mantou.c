// mantou.c ��ͷ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ͷ", ({"mantou"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��Ӳ���Ĵ���ͷ������ʹ�˵�θ�ڡ�\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
