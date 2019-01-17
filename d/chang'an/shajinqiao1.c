
// Room: /chang'an/shajinqiao1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "洒金桥");
        set("long", @LONG
这是一条青石铺就的大街。北面是一个拐角街口。东面是平民们仕途
的起点－－考场，但听说现在想做官比原来要难了，不但要考你的文学知
识，还要求你有一定的武力才行。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"kaochang",
                "south" : __DIR__"shajinqiao2",
                "west"  : __DIR__"caizhudamen",
                "north" : __DIR__"jiekou1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}