// yuebing.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("月饼", ({ "yuebing" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个金黄金黄的大月饼。\n");
                set("unit", "个");
                set("value", 0);
                set("food_remaining", 4);
                set("food_supply", 30);
        }
}

