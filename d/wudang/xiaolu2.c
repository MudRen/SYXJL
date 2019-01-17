// xiaolu2.c 林间小径
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "林间小径");
        set("long", @LONG
    你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶
声和鸟鸣声，听不到别的动静。�
LONG );
        set("exits", ([
                  "north" : __DIR__"xiaoyuan",
                "west" : __DIR__"xiaolu",
        ]));
        create_door("north", "竹门", "south", DOOR_CLOSED);
        set("objects", ([
                CLASS_D("wudang")+"/qingfeng": 1,
                CLASS_D("wudang")+"/mingyue": 1,
        ]));
        setup();
        replace_program(ROOM);
}

