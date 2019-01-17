inherit ROOM;

void create()
{
	set("short", "西单北大街");
	set("long", @LONG
这里是西单北大街。东边有一家很大的赌场，里面闹哄哄的。
北边是西四北大街。南边就是西单了。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"north" : __DIR__"xisi",
		"south" : __DIR__"xidan",
		"east" : __DIR__"duchang",
	]));
	set("objects", ([
	"/d/taishan/npc/seng-ren" : 1,
	]));


	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


