#include <room.h>

inherit ROOM;

void create()
{
	set("short", "青石阶");
	set("long", @LONG
这里山路渐宽，青石铺路，苔痕淡青，路左青松巍巍，路右藤
萝绕树，远远的，只见前方房宇依稀，赤红色旗帜招展，听说明教
烈火旗在此据守，数百年来固如磐石。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shanlu3",
		"northup" : __DIR__"lhqpaifang",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-150);
	set("coor/y",-50);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
