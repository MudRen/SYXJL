// rice.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Ã×·¹", ({ "rice" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÍëÏãÅçÅçÃ×·¹¡£\n");
                set("unit", "Íë");
                set("value", 0);
                set("food_remaining", 4);
                set("food_supply", 30);
        }
}

