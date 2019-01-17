// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "海港");
	set("long", @LONG
这里是出海的必经之地，从这里可以出海到桃花岛。目前正在施工中。
LONG
	);

	set("exits", ([
                "west" : __DIR__"zhongxin",
                "south" : __DIR__"yucun",
	]));

	set("objects", ([
                __DIR__"npc/boy":2,
                __DIR__"npc/girl":1,
	]));

        set("outdoors", "泉州");
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

