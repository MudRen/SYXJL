inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个藏在瀑布背后的山洞，借着瀑布外的微光可以看到山洞的大概轮
廓。这是一个很大的天然洞穴，空气中充满着很浓的硫磺味道，往东还有一个
内洞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"pubu",
  "east" : __DIR__"shdong2",
]));
	setup();
	replace_program(ROOM);
}
