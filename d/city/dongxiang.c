// Room: /city/dongxiang.c

// YZC 1995/12/04 



#include <room.h>

inherit ROOM;



void create()

{

	set("short", "财主东厢");

	set("long", @LONG

	这是一个昏暗的房间，窗户都被钉死。地上放着皮鞭、木棍等刑具，显然

这是财主私立公堂，折磨仆人、丫鬟的所在。一个丫鬟被绳子绑着，浑身赤裸跪在

地上哭哭啼啼，身上是一道道的伤口。

LONG

	);



	set("exits", ([

		"west" : __DIR__"houyuan",

	]));



	set("objects", ([

		"/d/marry/hongniang" : 1,

	]));

	setup();

	replace_program(ROOM);

}



