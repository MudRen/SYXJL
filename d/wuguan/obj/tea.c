// tea.c
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�����", ({ "tea"}) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ������衣\n");
                set("unit", "��");
                set("value", 0);
                set("max_liquid", 60);
        }
        set("liquid", ([
                "type": "water",
                "name": "ˮ",
                "remaining": 60,
        ]) );
}

