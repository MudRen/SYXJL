#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIC"����ذ��"NOR, ({"bi shou"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ƺ���̫������ذ�ף�����Ǹ�ʲô���\n������С����������\n");
                set("no_sell", "������������ã�\n");
                set("material", "gold");
                set("wield_msg", "$N�ͳ�һ��$n�������У���֪�Ǹ�ʲô��\n");
                set("unwield_msg", "$N�����е�$n���˻�ȥ��\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(10);
        setup();
}
