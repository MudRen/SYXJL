#include <weapon.h>
#include <ansi.h>

 inherit STAFF;

void create()
{
         set_name(HIG"打狗棒"NOR, ({ "dagou bang","bang", "staff"}) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500000);
     set("no_sell", 1);
      set("long", "一把绿油油的竹棒，这是丐帮帮主的信物。\n");
     set("wield_msg", "$N“铿”地一声，一道寒光闪过，拔出一把$n。\n");
     set("unwield_msg", "$N把$n插回腰间，嘴角露出一丝笑意。\n");
                set("material", "iron");
        }
         init_staff(300);
        setup();
}
