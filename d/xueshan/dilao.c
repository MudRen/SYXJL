//      dilao.c 地牢
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","地牢");
        set("long",@LONG
    这是一个阴暗、潮湿的牢房。
LONG
        );

        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));

        set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

