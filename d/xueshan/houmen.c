//      houmen.c 后门
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","后门");
        set("long",@LONG
    这是雪山寺的后门。
LONG
        );

        set("exits",([
                "south" : __DIR__"houyuan",
        ]));

        set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}



