// Room: /d/wuguan/dongwuchang1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "东练武场");
        set("long", @LONG
这是露天练武场，好多人在这里辛苦的练着，你走在场中，没有人
回头看你一眼，都在聚精汇神的练着自己的功夫，地上放着几个练功用
具。
LONG );
        set("outdoors", "wuguan");
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"dongwuchang",
                "north" : __DIR__"changlang2",
        ]));
        setup();
        replace_program(ROOM);
}
