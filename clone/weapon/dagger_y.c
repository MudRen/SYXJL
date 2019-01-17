#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIC"破烂匕首"NOR, ({"bi shou"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把似乎不太锋利的匕首，大概是个什么信物，\n刀身刻有“杨”的字样。\n");
                set("no_sell", "有人买这个破烂？\n");
                set("material", "gold");
                set("wield_msg", "$N掏出一把$n握在手中，不知是搞什么鬼！\n");
                set("unwield_msg", "$N将手中的$n插了回去。\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(10);
        setup();
}
