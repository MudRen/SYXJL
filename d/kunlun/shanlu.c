 // shanlu.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "西域山路");
                  set("long",@long
渐行渐西，天气一天冷似一天，西域昆仑派势力雄强，沿途倒并无什么强
盗，只是黄沙扑面，寒风透骨，却也着实难熬。
long);
                 set("exits",([
"west" : __DIR__"shanlu1",
"east" : __DIR__"shanjiao",
]));
set("outdoors", "昆仑");
set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",0);
	setup();
replace_program(ROOM);
}

