// tea.c
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("大碗茶", ({ "tea"}) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一杯大碗茶。\n");
                set("unit", "杯");
                set("value", 0);
                set("max_liquid", 60);
        }
        set("liquid", ([
                "type": "water",
                "name": "水",
                "remaining": 60,
        ]) );
}

