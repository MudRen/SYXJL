//Room: /d/dali/road6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","官道");
        set("long",@LONG
这是一条蜿蜒崎岖的山间土路，是由中原通向大理的官道。向北
不远就是蜀中浣花剑派的剑庐了。
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */ 
            "southwest"  : __DIR__"road1", 
            "northeast"  : __DIR__"road7",        ]));
        set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
