#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后园");
        set("long",
"这里是千佛庵的后园，这是一个极为宽阔的大院子，左右两边各有一\n"
"个庭院，西边的庭院是弟子们的寝房，东边的庭院是俗家弟子的寝房。\n"
        );

        set("exits", ([
		"north" : __DIR__"houmen",
                "south" : __DIR__"shendeng",
		"west" : __DIR__"huayuan1",
               ]));
        set("coor/x",-40);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",80);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}
