
// Room: /chang'an/yanhuaxiang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "烟花巷");
        set("long", @LONG
这是一条青石铺就的巷子。南面是一个很大的拐角街口。西面可以看
到一间很大的彩楼，不时有些气态庸俗的女子站在上面对着你勾勾手指头，
抛抛眉眼什么的。东面是一家赌场。这里原本是城内治安最坏的地方，经
过一段时间的整治，现在看起来要强了许多。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dufang",
                "south" : __DIR__"jiekou4",
                "west"  : __DIR__"yihongge",
                "north" : __DIR__"xidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}