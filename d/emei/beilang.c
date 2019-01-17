inherit ROOM;

void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是千佛庵北边的回廊，连接着西廊和神灯阁，成天人来人往不绝，
往西是千佛庵的北侧门，往东就可以到神灯阁了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xilang5",
  "east" : __DIR__"shendeng",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
