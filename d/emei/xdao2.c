inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
这里就是通往蛇窟的小道，狭窄的小道蜿蜒向上延伸。路的两旁杂草丛
生，偶尔有蛇在你脚下窜过，地上阴暗潮湿，正是虫蛇滋生的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shkrkou",
  "east" : __DIR__"xdao1",
]));
	set("no_clean_up", 0);

	set("coor/x",-90);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
