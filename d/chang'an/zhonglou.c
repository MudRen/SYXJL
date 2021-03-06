
// Room: /chang'an/zhonglou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "钟楼");
        set("long", @LONG
这里便是长安市的中心钟楼了。正东西南北四条大街交汇处。楼上有
大铁钟一口，每晨击钟报时，故名钟楼。钟楼高三十六米。从下向上由基
座、楼身和楼顶三部分组成，基座呈正方形，四面开券。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dongdajie3",
                "south" : __DIR__"nandajie2",
                "west"  : __DIR__"xidajie3",
                "north" : __DIR__"beidajie3",
                "up"    : __DIR__"zhonglouerceng",                             
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
