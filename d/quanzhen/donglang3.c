// donglang3.c 东厢走廊

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厢走廊");
	set("long", @LONG
	你走在一条走廊上，东边有几间雅室，人来人往很热闹。
LONG
	);

	set("exits", ([
	     "east" : __DIR__"xiuxishi",
           "west" : __DIR__"houdian",
       ]));

		
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	setup();
       replace_program(ROOM);

}
