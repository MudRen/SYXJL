#include <ansi.h>
inherit ITEM;
void create()
{
           set_name(HIW"���������顷"NOR, ({ "wumu yishu","shu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
             set("unit", "��");
             set("material", "paper");
              set("long", "�������������ı��顣\n");
          }

    setup();
}

