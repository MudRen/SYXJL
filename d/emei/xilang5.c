
inherit ROOM;

void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是千佛庵北边的回廊，是西廊和北廊的交汇处，成天人来人往不
绝，往西是千佛庵的北侧门，往东就可以到神灯阁了。				
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"beicemen",
  "south" : __DIR__"xilang4",
  "east" : __DIR__"beilang",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
