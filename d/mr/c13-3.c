#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","长廊");
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、
家丁们走来走去，都忙着自己的事情，东面是花肥房，北面是长廊的延
伸。
long);
         set("exits", ([
             "east" : __DIR__"hffang",
             "north" : __DIR__"c13-2",
]));
         set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}

