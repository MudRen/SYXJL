// Room: /d/gaibang/dlandao4.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
        set("short", "°µµÀ");
        set("long", @LONG
ÕâÊÇØ¤°ï¼«ÆäÃØÃÜµÄµØÏÂÍ¨µÀ£¬ÄËÓÃØ¤°ï¼¸±²ÈËÖ®ĞÄÑª¾ò³É¡£
ÄãÒşÒş¿´¼û²»Ô¶´¦ÓĞÒ»µã¹âÁÁ£¬ºÃÏóÊÇÒ»¸ö³ö¿Ú£¬²¢ÇÒÔ¶´¦ÒşÒş
Ô¼Ô¼´«À´Ò»Ğ©ÊĞ¾®µÄÉùÒô...£ 
LONG
        );

        set("exits", ([
                        "southdown" : __DIR__"dlandao3",
                        "out" : "/d/dali/dahejieeast",
        ]));

        setup();
        replace_program(ROOM);
}
