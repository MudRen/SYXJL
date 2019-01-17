#include <room.h>
inherit ROOM;

void create()
{
    set("short", "后厅");
	set("long", @LONG
这是归云庄的后厅。院中摆着几个机关人，是给桃花岛弟子练功用的。
厅后是一个大院。从这儿可以看到太湖的优美景色。
LONG
	);
    set("exits", ([
     "north" :__DIR__"gui-out",
     "south" :__DIR__"dayuan" ,
]));

    set("objects", ([
        __DIR__"npc/jiguan" : 2,
    ]) );
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
