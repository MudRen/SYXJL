inherit ROOM;

void create()
{
        set("short", "膳食房");
        set("long", @LONG
只见以经有十数名教徒分别围着几张八仙桌在进食，墙角有一张桌子是
空着的，周围摆着几张椅子，要填饱肚皮可以在那坐下。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"changlang4",
]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chuzi" : 1,
]));

        setup();
        replace_program(ROOM);
}
