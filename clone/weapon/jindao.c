#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(YEL"金刀"NOR, ({"jin dao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把纯金打造的蒙古匕首，刀把上镶嵌有白玉，\n刀身刻有“金刀驸马”的字样。\n");
                set("no_sell", "天下没人敢认买这个东西。\n");
                set("material", "gold");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，金光闪闪！\n");
                set("unwield_msg", "$N将手中的$n插入金色刀鞘。\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(10);
        setup();
}
