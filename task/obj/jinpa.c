// TIE@FY3
#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
         set_name(HIY"鸳鸯锦帕"NOR, ({ "jin pa","jin" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long",
            "一件发黄的肚兜,上面绣着: 
             四张机,鸳鸯织就欲双飞。
             可怜未老头先白。
             春波碧草，晓寒深处，相对浴红衣。\n"
          );
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/intelligence",2);
        }
        setup();
}

