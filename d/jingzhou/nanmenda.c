
// Room: /jingzhou/nanmendajie２.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "南门大街");
        set("long", @LONG
真是热闹非凡！东面的关庙和西面的女人街几乎是人山人海了，大街
上的人川流不息，挤挤攘攘，真是一片大好的繁华景象。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"guanmiao",
                "south" : __DIR__"nanmen",
                "west"  : __DIR__"nvrenjie1",
                "north" : __DIR__"nanmendajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}