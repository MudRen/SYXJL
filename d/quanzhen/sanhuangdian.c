// sanhuangdian.c 三皇殿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "三皇殿");
	set("long", @LONG
这里是三皇殿，三皇是传说中的远古帝王，具体所指有多种说法，
此殿供奉的是天皇（伏羲）、地皇（神农）、人皇（轩辕）。殿中放
了红木大香案，香案上供品齐备，香火十分旺盛。 
LONG
	);
       
	set("exits", ([
		"south" : __DIR__"donglang2",
		"north" : __DIR__"donglang4",
       ]));
	set("coor/x",-70);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",280);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}



