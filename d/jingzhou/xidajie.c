
// Room: /jingzhou/xidajie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
你走在西大街上，踩着坚实的青石板地面。西边是西城门，依稀可以
看到守城官兵的身影，与南边朗朗的读书声混杂在一起。北边是一家老字
号的书肆。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"xidajie2",
                "south" : __DIR__"sishu",
                "west"  : __DIR__"ximen",
                "north" : __DIR__"shusi",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}