//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","官道");
        set("long",@LONG
这是一条蜿蜒崎岖的山间土路，是由中原通向大理的官道。此处
属川南，向西南去的盘山路通上云贵山区，继而可达南昭大理国，此
去向北不远就是蜀中浣花剑派的剑庐了。
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */ 
            "southwest"  : __DIR__"road2", 
            "northeast"  : __DIR__"road6",        ]));
        set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
