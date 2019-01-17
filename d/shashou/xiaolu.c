// road.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
	这里是通往杀手楼的一条小山路，向四周望去，只
见一片片火红的枫林。你走在这里，四周静悄悄的，你就象
走进了一个世外桃源。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"enterance",
		"north" : __DIR__"fenglin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shashou" );

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
