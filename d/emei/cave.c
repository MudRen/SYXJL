
inherit ROOM;

void create()
{
	set("short", "��Ѩ");
	set("long", @LONG
����һ���տյ�ɽ����
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
