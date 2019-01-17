#include <room.h>
inherit ROOM;

void create()
{
        set("short", "长廊");
        set("long", @LONG
一条长长的过道，左右两旁都是墙，每隔四五丈，墙上都点着一支明晃
晃的巨烛。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"liangongfang",
  "east" : __DIR__"changlang4",
  "west" : __DIR__"qianqiudian",
]));
        set("no_clean_up", 0);
set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yang" : 1,
  __DIR__"npc/shizhe" : 2,
]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "日月神教") && dir == "north" &&
                objectp(present("yang", environment(me))))
           return notify_fail("杨莲亭喝道：你不是日月神教弟子，不得入内。\n");
                
        return ::valid_leave(me, dir);
}
