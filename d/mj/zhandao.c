// Room: zhandao.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short","栈道");
        set("long", @LONG
你好不容易爬上栈道，你发现有一群人正对着你笑。其中有
个人说：“小兄弟，欢迎！欢迎！欢迎加入我明教！今后我们就
是‘有富同享，有难同当’的兄弟了！！”南面就是明教的山门
了。
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shuobude" : 1,
  __DIR__"npc/mingjiaodizi" : 4,
]));
        set("no_out",1);
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shanlu1",
  "south" : __DIR__"shanmen",
]));

        set("coor/x",-80);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-80);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-80);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-80);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("id")=="mingjiao xunluo" && dir == "south" )
                return 0;
        return ::valid_leave(me, dir);
}

