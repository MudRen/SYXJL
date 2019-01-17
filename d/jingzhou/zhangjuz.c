
// Room: /jingzhou/zhangjuzhengjie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "张居正街");
        set("long", @LONG
临近北面的就是当地守军的驻扎地了，抬头可以看到军营刁斗上悬挂
的旗帜在风里猎猎飞舞。南面的路上却显得比较肮脏，原来是菜场。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "southeast" : __DIR__"caishikou",
                "west"  : __DIR__"jingzhonglu2",
                "north" : __DIR__"bingyingdamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}