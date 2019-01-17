inherit ROOM;

void create()
{
        set("short", "一品崖");
        set("long", @LONG
走过五老峰，前面是一道要命的峭壁“一品崖”，呼呼的山风阵阵
吹来，生怕鞋一滑被吹落下去，那就不大好赏景了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"wulao",
]));
        set("objects", ([
                __DIR__"npc/wolf": 2,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
