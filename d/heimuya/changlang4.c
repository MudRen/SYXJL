inherit ROOM;

void create()
{
        set("short", "长廊");
        set("long", @LONG
一条长长的过道，左右两旁都是墙，每隔四五丈，墙上都点着一支明晃
晃的巨烛。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"shifang",
  "south" : __DIR__"changlang6",
  "west" : __DIR__"changlang3",
  "north" : __DIR__"xiuxishi",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));

        setup();
        
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("gender") == "男性" )
                return notify_fail("看清楚，那是女弟子休息室！！，要睡到厢房去！\n");
        return ::valid_leave(me, dir);
}
