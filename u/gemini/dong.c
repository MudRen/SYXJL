// Room: /u/gemini/dong.c

inherit ROOM;

void create()
{
	set("short", "ɱ��¥");
	set("long", @LONG
�������һƬ��ʲô����������

LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"test.c",
]));

	setup();
	replace_program(ROOM);
}
