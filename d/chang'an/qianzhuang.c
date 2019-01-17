
// Room: /chang'an/qianzhuang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "钱庄");
        set("long", @LONG
这里是长安的钱庄，因为这里商业非常发达，各地的商号都和这里有
银钱来往。钱庄里有很多人在存取钱，也有人在兑换银两。看着这么多的
钱财滚来滚去，真是让人眼馋啊。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"beidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}