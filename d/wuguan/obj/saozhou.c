// chaidao.c

#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("ɨ��", ({ "saozhou" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ɨ�ص�ɨ�㣬��ͨ���յ��ճ���Ʒ��\n");
                set("value", 3);
                set("material", "����");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_club(5);
        setup();
}

