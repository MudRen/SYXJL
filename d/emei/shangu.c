
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"didao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
