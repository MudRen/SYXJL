// Room: /d/wuguan/changlang6.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这是个长廊，一直通向后院，南边是西练武场。
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"xiwuchang1",
                "north" : __DIR__"shibanlu3",                
        ]));
        setup();
        replace_program(ROOM);
}
