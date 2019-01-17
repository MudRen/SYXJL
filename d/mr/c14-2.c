#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","长廊");
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、
家丁们走来走去，都忙着自己的事情，东面是长廊的延伸，南面是客厅，
西面就是后院。
long);
         set("exits", ([
             "west" : __DIR__"houyuan",
             "south" : __DIR__"keting",
          "north" : __DIR__"c14",
             "east" : __DIR__"c14-3",
]));
         set("coor/x",130);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}
