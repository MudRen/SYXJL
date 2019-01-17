// Room: /u/gemini/dong.c

inherit ROOM;

void create()
{
	set("short", "杀手楼");
	set("long", @LONG
四周漆黑一片，什么都看不见。

LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"test.c",
]));

	setup();
	replace_program(ROOM);
}
