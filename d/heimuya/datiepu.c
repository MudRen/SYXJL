inherit ROOM;

void create()
{
        set("short", "打铁铺");
        set("long", @LONG
这是一家简陋的打铁铺，中心摆着一个火炉，炉火把四周照得一片通
红，你一走进去就感到浑身火热。墙角堆满了已完工和未完工的武器、
防具等物。一位铁匠满头大汗挥舞着铁锤，专心致志地在打铁。
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tie" : 1,
]));
       set("no_sleep_room", "1");
        set("no_fight", "1");
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"pailou",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
