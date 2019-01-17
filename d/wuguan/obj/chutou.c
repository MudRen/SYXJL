// chaidao.c

#include <weapon.h>

inherit AXE;

void create()
{
        set_name("锄头", ({ "chutou" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把用来锄地的锄头，普通百姓的日常用品。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_axe(5);
        setup();
}
