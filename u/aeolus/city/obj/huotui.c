// kaoya.c ¿¾Ñ¼

inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name("»ğÍÈ³¦", ({"huotui chang", "chang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "Ò»¸ùË«»ãÅÆµÄ»ğÍÈ³¦¡£\n");
          set("unit", "¸ù");
           set("value", 200);
           set("food_remaining", 3);
        set("food_supply", 40);
	}
}
