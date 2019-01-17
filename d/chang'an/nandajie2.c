
// Room: /chang'an/nandajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "南大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。南边就是朱雀门，北
面是中央广场，西面是一家马行。东边是一座两层的楼阁，挂着“悦来客
店”的招帘。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"yuelaikedian",
                "south" : __DIR__"gulou",
                "west"  : __DIR__"mahang",
                "north" : __DIR__"zhonglou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}