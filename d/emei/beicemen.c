inherit ROOM;

void create()
{
	set("short", "北侧门");
	set("long", @LONG
这里是千佛庵的北侧门，出北门有一条小道蜿蜒通往山上，但好象很
少有人经过这里，小道显得很是荒凉，杂草丛生，还不时有些小动物从路
上经过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xdao1",
  "east" : __DIR__"xilang5",
]));
	set("no_clean_up", 0);

	set("coor/x",-70);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
