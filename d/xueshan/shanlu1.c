//      shanlu1.c 山路
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","山路");
        set("long",@LONG
    这是一条上山的小路。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "westup" : __DIR__"shanlu2",
                "southdown" : __DIR__"shanjiao",
        ]));

        set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",-10);
	set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",-10);
	set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",-10);
	set("coor/x",-120);
	set("coor/y",50);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
