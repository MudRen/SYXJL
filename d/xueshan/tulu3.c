//      tulu3.c 土路
//      Designed by secret (秘密)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
    这是一条不起眼的土路。北边是著名的圣湖。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "south" : __DIR__"tulu2",
                "north" : __DIR__"shenghu",
        ]));

        set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

