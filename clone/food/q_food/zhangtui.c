inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("â¯ÍÈÈâ", ({"zhang tui"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éÏÊÑªÁÜÀì·ÊµÄâ¯ÍÈÈâ¡£\n");
                set("unit", "¿é");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
