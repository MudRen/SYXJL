// Room: /u/cuer/emei/jldong.c

inherit ROOM;

void create()
{
	set("short", "九老洞");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiaojin3",
]));
	set("no_clean_up", 0);

	set("coor/x",-90);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
