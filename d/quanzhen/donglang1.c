// donglang1.c 东厢走廊

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厢走廊");
	set("long", @LONG
你走在一条长廊上，人来人往很热闹。房顶一侧支在北面的灵官殿上，
另一侧则与西边三清殿的屋顶相连。走廊二边的墙上刻着的是二十四孝的
图形，每一幅图案都有一个生动的故事。往西是三清殿，往北是灵官殿。
LONG
	);

	set("exits", ([
		"north" : __DIR__"lingguandian",
		"west" : __DIR__"sanqingdian",
	]));
	
	set("coor/x",-80);
	set("coor/y",250);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",250);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",250);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",250);
	set("coor/z",190);
	setup();
       replace_program(ROOM);

}

