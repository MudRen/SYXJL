
// Room: /chang'an/dufang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "金钩赌坊");
        set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。西边进
去是赌「大小」的房间，北边是赌「牌九」的房间(建设中)。墙上显眼处
挂着一块牌子(paizi)。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"yanhuaxiang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}