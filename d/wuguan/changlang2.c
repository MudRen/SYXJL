// Room: /d/wuguan/changlang2.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这是个长廊，北面是武馆内的物品房，要在武馆做杂事的人都得去
物品房领工具，南边是东练武场。
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"dongwuchang1",
                "north" : __DIR__"wupingfang",                
        ]));
        setup();
        replace_program(ROOM);
}
