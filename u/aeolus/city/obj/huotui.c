// kaoya.c ��Ѽ

inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name("���ȳ�", ({"huotui chang", "chang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ��˫���ƵĻ��ȳ���\n");
          set("unit", "��");
           set("value", 200);
           set("food_remaining", 3);
        set("food_supply", 40);
	}
}
