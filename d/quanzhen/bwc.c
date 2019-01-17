// Room: bwc.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "比武场");
        set("long", @LONG
这里是全真教的比武场，广场的两边放着十八般兵器和练功木人，全
真教自王重阳传下门规，每年除夕前三日，门下第子大较武功，考查这一
年来各人的进境。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guangchang",
 ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx"); 
        set("objects", ([
                __DIR__"npc/muren" : 3, 
   ]));
        set("coor/x",-80);
	set("coor/y",230);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",230);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",230);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",230);
	set("coor/z",190);
	setup();
        replace_program(ROOM);
}

