#include <ansi.h>
inherit ITEM;
void create()
{
       set_name(HIY"金"MAG"锁片"NOR, ({ "jin suopian","suopian","jin" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
             set("unit", "个");
            set("material", "gold");
              set("long",
           "一个金锁片，上面刻着:
                 湖边竹，盈盈绿，报平安，多喜乐。\n"
             );

          }

    setup();
}


