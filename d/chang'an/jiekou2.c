// Room: /chang'an/jiekou2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "街口");
        set("long", @LONG
这儿是拐角街口，有很多小商小贩们在向行人吆喝着，兜售他们的商
品。西面和南面是青石铺就的大街。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"chongwujie",
                "south" : __DIR__"shangdelu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}