// najidian.c 南极殿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "南极殿");
	set("long", @LONG
这里是南极殿，南极大帝是天上二十八星宿之首，所以又称寿星，
被看作人间寿夭之神。殿中放了红木大香案，香案上供品齐备，香火
十分旺盛。 
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"xilang2",
		"northwest" : __DIR__"xilang4",
       ]));
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}



