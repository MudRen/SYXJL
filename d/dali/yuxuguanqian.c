//Room: /d/dali/yuxuguanqian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","玉虚观前");
	set("long",@LONG
东面一座庙观，门前匾上写着“玉虚观”三个大字，西边一个
碧水荡漾的小湖，四周绿柳成荫，实乃修心养性的好地方。
LONG);
	set("objects", ([
	   __DIR__"npc/xiaodaogu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yuxuguan",
	    "south"  : __DIR__"hudiequan",
	]));
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}

