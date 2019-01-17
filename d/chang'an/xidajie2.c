
// Room: /chang'an/xidajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
这儿是很大的十字街口，北边进进出出的人络绎不绝，南面听说是本
城治安最差的地方，龙蛇混杂，听说最近知府大人下令严治该区，不知道
有没有成果。东边通向钟楼，西面可达玉祥门。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"xidajie3",
                "south" : __DIR__"yanhuaxiang",
                "west"  : __DIR__"xidajie1",
                "north" : __DIR__"shajinqiao2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}