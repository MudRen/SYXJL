#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "花园");
        set("long",
"从后院往西走就到了这里，这是一个大花园，长满了各种奇花异草。\n"
"四周就是弟子们的寝房了，所以虽然有弟子不断进进出出，但还是很安静。\n"
        );

        set("exits", ([
		"north" : __DIR__"room1",
                "south" : __DIR__"room3",
		"east" : __DIR__"houyuan",
		"west" : __DIR__"room2",
               ]));
        set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}