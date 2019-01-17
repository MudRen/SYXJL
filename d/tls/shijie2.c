// shijie2.c 石阶

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
你走在一条坚实的石阶上，不时地有进香客从你的身边走过。
LONG
	);
        set("outdoors", "tianlongsi");

	set("exits", ([
		"west" : __DIR__"shijie1",
		"east" : __DIR__"jietan",
	]));
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

