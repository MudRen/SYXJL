// yangrou.c ÑòÈâ
// by QingP

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ÑòÈâ", ({"yang rou", "rou"}));
        set_weight(700);
        set("long", "Ò»¿éĞÂÏÊµÄÑòÈâ¡£\n");
        set("unit", "¿é");
        set("value", 3000);
        set("food_remaining", 7);
        set("food_supply", 200);
}