// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "赌场");
        set("long", @LONG
        这里有两条走廊通向不同的房间，
        里面传来赌徒喧闹的声音,"快呀，快呀......咬哇，咬......"。
LONG
        );

        set("exits", ([
                //"east" : "/inherit/room/eproom",
                //"west" : "/inherit/room/wproom",
                //"south" : "/inherit/room/sproom",
                //"north" : "/inherit/room/nproom",
                "down" : __DIR__"duchang2",
                "east" : __DIR__"duchang4",
                "west" : __DIR__"duchang5",
                
                
        ]));

        set("coor/x",-10);
        set("coor/y",-10);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}

