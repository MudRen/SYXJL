
// Room: /jingzhou/nvlao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女牢");
        set("long", @LONG
黑糊糊的几乎什么都看不清楚，头上偶尔听到蝙蝠扑腾翅膀的声音，蚊
子多得要命，反正它们在这里也不分黑夜和白天，每日里只有半　个又黑又
硬的馒头和一碗大概是在畜生的水漕里装来的水，脏得要死。这里的人不算
很多，由于在这里呆上一段时间，个个几乎都已经看不出她们的性别了。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jianyuguodao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}