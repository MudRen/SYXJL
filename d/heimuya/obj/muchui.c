#include <weapon.h>



inherit HAMMER;



void create()

{

        set_name("ľ���", ({ "muyu chui", "chui" }) );

        set_weight(500);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "��");

                set("value", 50);

                set("material", "wood");

                set("long", "����һ����ͨ��Сľ颡� \n");

                set("wield_msg", "$N���´����ͳ�һ��$n���������е�������\n");

                set("unequip_msg", "$N�����е�$n�Ż��´���\n");

                set("shaolin",1);

        }

        init_hammer(1);

        setup();

}



void init()

{

       add_action("do_noexpnohappy", "noexpnohappy");

}



int do_noexpnohappy()

{

        object me = this_player();

      me->add("potential",100);

        return 1;

}

