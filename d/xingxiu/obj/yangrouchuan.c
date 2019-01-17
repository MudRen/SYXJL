// yangrouchuan.c —Ú»‚¥Æ
// by QingP

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("—Ú»‚¥Æ", ({"yangrou chuan", "yangrou", "chuan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "“ª¥Æœ„≈Á≈Áµƒ—Ú»‚¥Æ£¨…œ√Ê’¥¬˙¡À◊Œ»ª∫Õ¿±Ω∑√Ê°£\n");
                set("unit", "¥Æ");
                set("value", 200);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

