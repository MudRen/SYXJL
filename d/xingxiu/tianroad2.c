// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "天山山路");
        set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片草原。
路尽头有一片松林。北上就是人人害怕的灵鹫宫了.
LONG
        );
        set("exits", ([
            "northup" : "/d/lingjiu/shanjiao",
            "northdown" : __DIR__"xxh1",
            "south" : __DIR__"tianroad1",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	set("coor/x",-120);
	set("coor/y",40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}