
// Room: /chang'an/deshanglu3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "德尚路");
        set("long", @LONG
这是一条青石铺就的大街，向南北两头延伸。北面是一个看起来很大
的十字路口。南面是一个拐角街口。东面是一家丝绸铺子，看起来生活还
挺红火。西面是一家杂货铺。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"sichouhang",
                "south" : __DIR__"jiekou3",
                "west"  : __DIR__"zahuopu",
                "north" : __DIR__"dongdajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}