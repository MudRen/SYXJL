
inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shangu",
  "south" : __DIR__"didao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
