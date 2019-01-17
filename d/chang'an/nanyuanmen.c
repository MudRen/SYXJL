
// Room: /chang'an/nanyuanmen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "南院门");
        set("long", @LONG
这是一条幽深的阔巷，地上没有铺设石面，走在上面倒觉得舒服。西
面是钟楼。北面是城内的一间学堂，不时能听到学堂里传来学生们朗朗地
读书声。南面有一家小极了的饭店。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jiekou3",
                "south" : __DIR__"laosunjia",
                "west"  : __DIR__"gulou",
                "north" : __DIR__"xuetang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}