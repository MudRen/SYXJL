
// Room: /chang'an/shajinqiao2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "洒金桥");
        set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。东面是武校场，是平
民仕途的另一个起点，考上了可以当上一名地位低微的武官。但听说现在
不象以前了，不但要考你的武功，还要要求你有一定的文学基础。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jiaochang",
                "south" : __DIR__"xidajie2",
                "west"  : __DIR__"zhenxibiaoju",
                "north" : __DIR__"shajinqiao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}