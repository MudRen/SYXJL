// piao.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ˮư", ({ "piao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻ����Ҩˮ��ˮư����ͨ���յ��ճ���Ʒ��\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һֻ$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(5);
        setup();
}

