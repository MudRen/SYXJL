//add by angle
//underyzw.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "破洞口");
        set("long", @LONG
这是一个破破烂烂的小地洞，上方好象有几丝光芒投射下来，上面是
什么地方呢，还是上去看看吧！
LONG );
        set("exits", ([
                "southwest" : __DIR__"yzwandao2",
                "out" : "/d/mr/yanziwu",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
