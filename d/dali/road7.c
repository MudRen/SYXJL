//Room: /d/dali/road7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","小道");
        set("long",@LONG
这是一条蜿蜒崎岖的山间小道，这里地处川滇交界处，往北不远处便是
浣花剑派的剑庐。往南是通往南昭大理国的官道。
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */ 
            "southwest"  : __DIR__"road6", 
            "northeast"  : "/d/huanhua/podi",        ]));
        set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-120);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
