inherit ROOM;

void create()
{
        set("short", "后花园");
        set("long", @LONG
此处种满了许多不知名的奇花异草，在绝顶之上有这样的景色，真恍如
飘渺仙景，令人疑幻疑真，西首是一间小石屋，但似乎没有人居住。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jueya",
  "north" : __DIR__"changlang5",
  "west" : __DIR__"xiaosiwu",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhang" : 1,
  __DIR__"npc/lan" : 1,
]));

        setup();
        replace_program(ROOM);
}
