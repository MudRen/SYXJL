//fende.c

inherit ROOM;

void create()
{
	set("short", "坟地");
	set("long",
	     "这里是荒凉阴森的荒坟地。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
	]));
	set("objects" , ([
	     __DIR__"npc/guafu" : 1,
	     ]) );
	set("coor/x",-80);
	set("coor/y",-50);
	set("coor/z",-30);
	set("coor/x",-80);
	set("coor/y",-50);
	set("coor/z",-30);
	set("coor/x",-80);
	set("coor/y",-50);
	set("coor/z",-30);
	set("coor/x",-80);
	set("coor/y",-50);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
