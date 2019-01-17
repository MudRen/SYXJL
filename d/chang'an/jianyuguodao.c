// Room: /chang'an/jianyuguodao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "监狱过道");
        set("long", @LONG
一条黑黑的走廊，只有一盏油灯发出一点微弱的光，到处是一股难闻
的霉臭味道
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"silao",
                "south" : __DIR__"nanlao",
                "west"  : __DIR__"jianyudamen",
                "north" : __DIR__"nvlao",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}