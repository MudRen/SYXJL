//shepi



#include <armor.h>



inherit CLOTH;



void create()

{

        set_name( "蛇皮", ({ "she pi", "pi" }) );

       set("long", "这是一张蛇皮。\n");

set_weight(1000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "张");

              set("value",550);

                set("material", "leather");

                set("armor_prop/armor", 10);

        }

        setup();

}

