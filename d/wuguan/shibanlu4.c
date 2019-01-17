// Room: /d/wuguan/shibanlu4.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
你走在一条石板路上，北面过去就是后院了。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"shibanlu3",
                "north" : __DIR__"houyuan",
        ]));
        setup();
        replace_program(ROOM);
}
