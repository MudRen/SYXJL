// kaoya.c ��Ѽ

inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name("��������", ({"gui yu", "guiyu", "yu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ĺ����������㡣\n");
          set("unit", "��");
           set("value", 1000);
           set("food_remaining", 10);
         set("food_supply", 100);
	}
}
