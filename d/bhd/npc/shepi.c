//shepi



#include <armor.h>



inherit CLOTH;



void create()

{

        set_name( "��Ƥ", ({ "she pi", "pi" }) );

       set("long", "����һ����Ƥ��\n");

set_weight(1000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "��");

              set("value",550);

                set("material", "leather");

                set("armor_prop/armor", 10);

        }

        setup();

}
