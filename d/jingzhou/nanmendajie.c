
// Room: /jingzhou/nanmendajie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "南门大街");
        set("long", @LONG
这里是荆州最为繁华的地段，路上到处都是人，你不由得放慢脚步才
行，东面有一块很大的“当”字招牌，西面隔老远就可以闻到一股刺鼻的
药材味道。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"dangpu",
                "south" : __DIR__"nanmendajie2",
                "west"  : __DIR__"yaopu",
                "north" : __DIR__"huatai",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}