// Room: /u/cuer/emei/jldong.c

inherit ROOM;

void create()
{
	set("short", "���϶�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
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
