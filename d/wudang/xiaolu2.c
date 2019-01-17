// xiaolu2.c ÁÖ¼äĞ¡¾¶
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ÁÖ¼äĞ¡¾¶");
        set("long", @LONG
    Äã×ßÔÚÒ»ÌõĞ¡¾¶ÉÏ£¬Á½ÅÔÖÖÂúÁËÖñ×Ó£¬ĞŞóòÉ­É­£¬ÂÌÒñÂúµØ£¬³ıÁËÖñÒ¶
ÉùºÍÄñÃùÉù£¬Ìı²»µ½±ğµÄ¶¯¾²¡££
LONG );
        set("exits", ([
                  "north" : __DIR__"xiaoyuan",
                "west" : __DIR__"xiaolu",
        ]));
        create_door("north", "ÖñÃÅ", "south", DOOR_CLOSED);
        set("objects", ([
                CLASS_D("wudang")+"/qingfeng": 1,
                CLASS_D("wudang")+"/mingyue": 1,
        ]));
        setup();
        replace_program(ROOM);
}

