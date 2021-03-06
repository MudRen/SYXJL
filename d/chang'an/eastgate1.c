// Room: /d/chang'an/eastgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "朝阳内门");
	set("long", 
"这里是长安城的东城门的内城门，只见城门上方是三个大字。"HIG"

                       朝    阳    门
\n"NOR
"    长安是西北经济中心，丝绸之路的起点，由于朝廷禁止偷运走私蚕籽
之类的物品出关，所以在这里已经盘查得十分严格了。两边是上城头的石
阶，向西进入城区。\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"southup" : __DIR__"walle1",
		"northup" : __DIR__"walle2",
		"west"    : __DIR__"dongdajie1",
		"east"    : __DIR__"eastgate2",
	]));
	setup();
	replace_program(ROOM);
}

