// chaidao.c

#include <weapon.h>

inherit AXE;

void create()
{
        set_name("��ͷ", ({ "chutou" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������صĳ�ͷ����ͨ���յ��ճ���Ʒ��\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_axe(5);
        setup();
}
