//      zoulang3.c 走廊
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","走廊");
        set("long",@LONG
    这里是雪山寺内的走廊。
LONG
        );

        set("exits",([
                "north" : __DIR__"neidian",
                "eastdown" : __DIR__"zoulang1",
                "westdown" : __DIR__"zoulang2",
        ]));

        set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",60);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",60);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",60);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",60);
	setup();
        replace_program(ROOM);
}

