#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"��"RED"��Ƭ"NOR, ({ "jin suopian","suopian","jin" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
             set("unit", "��");
            set("material", "gold");
              set("long",
           "һ������Ƭ���������:
                �����ǣ��������������ã���������\n"
             );

          }

    setup();
}

