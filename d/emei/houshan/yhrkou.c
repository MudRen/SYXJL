inherit ROOM;

void create()
{
	set("short", "云海入口");
	set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都是云雾，根本就弄
不清自己身在何出。在雾中隐隐约约有一条小道通向前方，还是回去吧。
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"yunhai0",
  "southeast" : __DIR__"shandao2",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",120);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
