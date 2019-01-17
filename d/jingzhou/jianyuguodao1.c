
// Room: /jingzhou/jianyuguodao1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "监狱过道");
        set("long", @LONG
一进来就给人阴森的感觉，阴暗的牢房散发着一股霉臭的味道。由于荆
楚民风刁悍，违法的人看来还不少，几乎把这里塞得满满的，左边是死囚的
关押地，右边是刚刚抓进来还没有定罪的犯人。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nanlao",
                "south" : __DIR__"jianyuguodao2",
                "west"  : __DIR__"nvlao",
                "north" : __DIR__"jianyudamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}