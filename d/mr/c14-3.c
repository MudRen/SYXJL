#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","长廊");
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、
家丁们走来走去，都忙着自己的事情，南面是长廊的延伸。
long);
         set("exits", ([
             "west" : __DIR__"c14-2",
             "south" : __DIR__"c14-4",
             "east" : __DIR__"fanting",
]));
         set("coor/x",140);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
//         replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (dir == "east" && me->query("family/family_name") != "姑苏慕容"
        && objectp(present("jia ding", environment(me))))
                return notify_fail("家丁喝道：“到慕容山庄不要乱闯”。\n");

        return ::valid_leave(me, dir);
} 
