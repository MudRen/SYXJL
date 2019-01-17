
// Room: /jingzhou/sanyijie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "三义街");
        set("long", @LONG
这条街的由来是根据三国时候刘关张桃园三结义的典故而命名的，两
边的建筑几乎都是木制阁楼，看起来气派得很。东面是一家酒楼，西面看
起来似乎是一间客栈。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jiulou",
                "south" : __DIR__"sanyijie",
                "west"  : __DIR__"kedian",
                "north" : __DIR__"beimen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}