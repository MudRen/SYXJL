// Room: /d/quanzhou/nanmen.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "泉州南门");
	set("long", @LONG
这里是南方第一港泉州的南门。南门外是一片荒野。
LONG
	);

	set("exits", ([
		"south" : __DIR__"bamboo",
                "north" : __DIR__"zhongxin",
	]));

	set("outdoors", "quanzhou");
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

