
inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG
这是一个空空的山洞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"didao1",
  "out" : __DIR__"fhuang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
