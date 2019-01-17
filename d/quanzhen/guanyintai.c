// guanyintai.c 观音台 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "观音台");
	set("long", @LONG
观音台又称大台，位于独松阁之上，有隋国光寺遗址。台视角开阔，往
北可眺八百里秦川，令人胸襟为之一开，心旷神怡。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
	    "southdown" : __DIR__"dusongge",
	    "eastup" : __DIR__"gaoguanpubu",
      	]));
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}



