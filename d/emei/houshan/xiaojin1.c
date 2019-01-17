inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这是一条曲径通幽的小道，两边是翠竹成行，耳中可以听闻到悦耳的鸟
鸣。一条小溪伴在小路的傍边，前方就是著名的九老洞了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shandao2",
  "west" : __DIR__"xiaojin2",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
