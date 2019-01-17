
// Room: /huoshan/jingsishi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "静思室");
        set("long", @LONG
一间空荡荡的房子，四面的墙壁(qiang)冷冰冰的，地上放着几
个绒制的垫子，安静的环境可以让你在这里面壁静思。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"zoulang5",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}