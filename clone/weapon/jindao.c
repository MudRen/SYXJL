#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(YEL"��"NOR, ({"jin dao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѵ��������ɹ�ذ�ף���������Ƕ�а���\n������С���������������\n");
                set("no_sell", "����û�˸��������������\n");
                set("material", "gold");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У����������\n");
                set("unwield_msg", "$N�����е�$n�����ɫ���ʡ�\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(10);
        setup();
}
