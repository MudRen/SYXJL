//shanshiting.c

inherit ROOM;

void create()
{
	set("short", "膳食厅");
	set("long", @LONG
你看到这里已经密密麻麻坐满了浣花弟子，围着八仙桌在用膳。一个
老厨子恭敬地向你迎了过来，指了指大厅角落里的剩下的唯一一张瘸
了腿的小桌，无奈地对你耸了耸肩。
LONG
	);

	set("exits", ([
               "north" : __DIR__"changlang2",
		]));
	set("objects", ([
		  "/d/city/obj/baozi" : 3,
	]));

	setup();
	replace_program(ROOM);
}
