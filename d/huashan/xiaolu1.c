// xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "小山路");
	set("long", @LONG
这里是华山的一条小山路，地势较为平缓，不似其它地方那么险峻。
你走在这里，四周静悄悄的，你就象走进了一个世外桃源。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"yunu",
		"northeast" : __DIR__"xiaolu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}