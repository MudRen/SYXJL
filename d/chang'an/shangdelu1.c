// Room: /chang'an/shangdelu1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "尚德路");
        set("long", @LONG
这是一条青石铺就的大街。西面是一堵盖着青瓦的大房子，不是看见
一些官差进进出出，原来那里就是巡捕房了。北面是就是刑场，看起来很
吓人。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"xunbufang",
                "south" : __DIR__"shangdelu2",
                "west"  : __DIR__"xingchang",
                "north" : __DIR__"jiekou2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}