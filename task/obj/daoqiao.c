#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"寒萸刀鞘"NOR, ({ "daoqiao" }) );
        set_weight(8000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("for_bandit2",1);
                set("long", "一个用天山上千年寒萸做成的刀鞘。\n");
        }
}

int is_container() { return 1; }


