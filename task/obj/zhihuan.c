#include <ansi.h>
inherit ITEM;
void create()
{
          set_name(BLU"��ʯ"HIY"ָ��"NOR, ({ "tie zhihuan","zhihuan"}) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
              set("unit", "ö");
            set("material", "gold");
           set("long","һö��������ʯ����ָ��������ң�ɵ��������\n");

          }

    setup();
}


