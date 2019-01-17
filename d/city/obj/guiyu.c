// kaoya.c ¿¾Ñ¼

inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name("ËÉÊó÷¬Óã", ({"gui yu", "guiyu", "yu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌÏãÅçÅçµÄºìÉÕËÉÊó÷¬Óã¡£\n");
          set("unit", "ÅÌ");
           set("value", 1000);
           set("food_remaining", 10);
         set("food_supply", 100);
	}
}
