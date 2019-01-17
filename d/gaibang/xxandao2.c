// Room: /d/gaibang/xxandao2.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;



void create()

{

	set("short", "暗道");

	set("long", @LONG

这里是星宿海日月洞旁的一个小洞。里面破破烂烂的，丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG

	);



	set("exits", ([

                        "out" : "/d/xingxiu/xxh2",

			"east" : __DIR__"xxandao1",

	]));



	set("objects",([

                CLASS_D("gaibang") + "/huo-du" : 1,
		"/d/city/obj/jitui" : 3,

		"/d/city/obj/jiudai" : 1,

	]));



	setup();

	replace_program(ROOM);

}







