//      midao.c 密道
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","密道");
        set("long",@LONG
    这是一条狭窄的暗道。
LONG
        );

        set("exits",([
                "north" : __DIR__"mishi",
                "east" : __DIR__"neidian",
        ]));

        set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",60);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",60);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",60);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",60);
	setup();
        replace_program(ROOM);
}
