// Room: /d/chang'an/southgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "朱雀内门");
	set("long", 
"这里是长安城的南城门的内城门，只见城门上方是三个大字。
"HIR"
                      朱    雀    门
\n"NOR
"    长安是西北经济中心，丝绸之路的起点，由于朝廷禁止偷运走私蚕籽
之类的物品出关，所以在这里已经盘查得十分严格了。两边是上城头的石
阶，向北进入城区。\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"eastup" : __DIR__"walls2",
		"westup" : __DIR__"walls1",
		"south"  : __DIR__"southgate2",
		"north"  : __DIR__"nandajie1",
	]));
	setup();
	replace_program(ROOM);
}

