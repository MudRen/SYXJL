
// Room: /chang'an/yizhan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "驿站");
        set("long", @LONG
这里就是长安城内的大驿站了，由于此地公务繁多，进进出出的快马
一天不知道有多少，看着驿使风尘仆仆的样子，确实是一件非常辛苦的事
情。官府里的低级官员可以在这里领取任务。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"dongdajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}