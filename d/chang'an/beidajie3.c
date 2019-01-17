
// Room: /chang'an/beidajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "北大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。北面是一座鼓楼，看
起来是一座很高大的建筑。南面紧连的是钟楼，看起来热闹非凡。西面是
一家当铺，向东可以到钱庄。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"qianzhuang",
                "south" : __DIR__"zhonglou",
                "west"  : __DIR__"dangpu",
                "north" : __DIR__"beidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}