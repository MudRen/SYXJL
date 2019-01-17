// Room: /d/chang'an/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "朱雀外门");
	set("long", 
"这里是长安城的南城门，只见城门上方是三个大字。"HIR"

                       朱    雀    门
\n"NOR
"    长安是西北经济中心，丝绸之路的起点，由于朝廷禁止偷运走私蚕籽
之类的物品出关，所以在这里已经开始盘查得十分严格了。两边是很大的
草地。\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
                "north"  : __DIR__"southgate1",
	]));
/*
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
*/
	setup();
	replace_program(ROOM);
}

