
// Room: /jingzhou/yingdulu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "郢都路");
        set("long", @LONG
此街的来由大概就是因为原来楚过曾经定都于此的缘故，这条街街面
比较窄，但西面的茶馆到有不少人坐在那里悠闲地听书，东面是一家木匠
店铺。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"mujiangdian",
                "south" : __DIR__"huadian",
                "west"  : __DIR__"chaguan",
                "north" : __DIR__"xidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}