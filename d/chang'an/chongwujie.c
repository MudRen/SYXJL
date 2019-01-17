
// Room: /chang'an/chongwujie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "崇武街");
        set("long", @LONG
这是一条青石铺就的巷子。向东西两头延伸。东面是一个拐角大街。
北面是长安武馆，听说武馆里的教头叶小钗曾经也是江湖中人，还闯出过
一番名堂来，人称“江湖笑笑猫”。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jiekou2",
                "west"  : __DIR__"beidajie2",
                "north" : __DIR__"changanwuguan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}