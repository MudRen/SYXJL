// Room: /d/quanzhou/yanyu.c
// Date: May 23, 96   Jay

inherit ROOM;

void create()
{
	set("short", "烟雨楼");
	set("long", @LONG
烟雨楼建在南湖中心的一个小岛上。南湖终年不断的水气把它
笼罩得迷迷蒙蒙的。楼内是家饭店。
店内正在装修楼梯。请勿上楼。
LONG
	);

	set("exits", ([
                "north" : __DIR__ "nanhu1",
	]));

	set("outdoors", "quanzhou");
        set("objects", ([
            __DIR__"npc/xiaoer" : 1]));

	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

