// xiangfang3.c 厢房

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这里是金莲阁，
LONG
	);
        
	set("exits", ([
		"" : __DIR__"",
		"" : __DIR__"",
        ]));
	setup();
	replace_program(ROOM);
}



