#include <ansi.h>
inherit ITEM;
void create()
{
          set_name(BLU"宝石"HIY"指环"NOR, ({ "tie zhihuan","zhihuan"}) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
              set("unit", "枚");
            set("material", "gold");
           set("long","一枚镶着蓝宝石的铁指环，是逍遥派的掌门信物。\n");

          }

    setup();
}


