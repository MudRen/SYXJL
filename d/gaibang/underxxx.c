// Room: /d/gaibang/undertree.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;









void create()

{

        set("short", "大厅下");
	set("long", @LONG

这是神龙教大厅下的一个密洞。里面破破烂烂的，丢满了各种
杂物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通

道。

LONG

	);



	set("exits", ([

               "out" : "/d/shenlong/dating",

               "east":__DIR__"shenlongdao2",

	]));



	set("objects",([

		CLASS_D("gaibang") + "/yu-hx" : 1,

	]));



	setup();

	replace_program(ROOM);

}







