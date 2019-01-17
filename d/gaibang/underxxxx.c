// Room: /d/gaibang/undertree.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;









void create()

{

        set("short", "大厅旁");

	set("long", @LONG

这是桃花岛大厅旁边的小洞。里面破破烂烂的，丢满了各种杂物   
，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。

LONG

	);



	set("exits", ([

               "out" : "/d/taohua/dating",

               "east":__DIR__"ttaohua2",

	]));



	set("objects",([

                  CLASS_D("gaibang") + "/li-fu" : 1,

	]));



	setup();

	replace_program(ROOM);

}







