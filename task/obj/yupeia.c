#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"金"RED"锁片"NOR, ({ "jin suopian","suopian","jin" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
             set("unit", "个");
            set("material", "gold");
              set("long",
           "一个金锁片，上面刻着:
                天上星，亮晶晶，永灿烂，长安宁。\n"
             );

          }

    setup();
}


