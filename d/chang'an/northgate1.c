// Room: /d/chang'an/northgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "玄武内门");
	set("long", 
  "这里是长安城的北城门的内城门，只见城门上方是三个大字。
"HIB"
                    玄    武    门
\n"NOR
"    长安是西北经济中心，丝绸之路的起点，由于朝廷禁止偷运走私蚕籽
之类的物品出关，所以在这里已经开始盘查得十分严格了。两边是上城头
的石阶，向南进入城区。\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"eastup" : __DIR__"walln1",
		"westup" : __DIR__"walln2",
		"south"  : __DIR__"beidajie1",
		"north"  : __DIR__"northgate2",
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

