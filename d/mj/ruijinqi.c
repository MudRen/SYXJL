// Room: ruijinqi.c

inherit ROOM;

void create()
{
        set("short", "锐金旗");
        set("long", @LONG
你进到这里就感到一股热浪扑面而来，只见正中的巨大火炉正喷
出炙热火焰，四周几个大汉正用力打造手里的兵器，汗水滴在炉台上
冒出阵阵白雾。这里就是教中的锐金旗，教中厉害无比的机关、暗器
和铜人都出自这里的能工巧匠之手。

LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wujingcao" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jumuqi",
  "east" : __DIR__"lianwu-chang4",
]));
        set("no_clean_up", 0);
        set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

