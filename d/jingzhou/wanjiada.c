
// Room: /jingzhou/wanjiadayuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "万家大院");
        set("long", @LONG
你走进大院，迎面是一个假山水池，池上摆着一块奇形怪状的石头，
据说是当年花石纲的遗石。水池的两旁种满了花草。东边是一棵槐树，郁
郁葱葱，遮盖了大半个院子。一条长廊走道通往后院。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"wanjiadazhai",
                "west"  : __DIR__"wanjiahouyuan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}