// TIE@FY3
#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name(HIR"金红散花衣"NOR, ({ "huaqun" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件金边淡红缀满蓝花的衣服\n");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/intelligence",2);
        }
        setup();
}

