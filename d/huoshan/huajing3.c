
// Room: /huoshan/huajin3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "花径");
        set("long", @LONG
你正走在一条两边开满鲜花的小径上，路边的花开得争奇斗妍，
这里的花你大都能叫出名字来，令你感到惊讶的是这里的花全是难
求的名品，有些只有在皇宫或者将相王侯的府邸里有专门的花工精
心培育的花，在这里比比皆是，自由地这样开在野外，你不知应该
是为花感到庆幸或者是惋惜。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"huajing4",
                "northdown" : __DIR__"huajing2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}