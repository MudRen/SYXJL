
// Room: /chang'an/beidajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "北大街");
        set("long", @LONG
你走在一条宽阔的青石街面上，这里是城内最大的一个十字路口，往
来的人络绎不绝。西面是药王洞，向东可达崇武街。向南已经可以看见高
高矗立的钟楼了。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"chongwujie",
                "south" : __DIR__"beidajie3",
                "west"  : __DIR__"yaowangdong",
                "north" : __DIR__"beidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}