
// Room: /jingzhou/yamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "衙门");
        set("long", @LONG
比起本地发将军府，衙门可是要威风得多了，衙役们操着水火棍精神
抖擞地立在两边。东面有一面大鼓（gu），是用来击鼓喊冤用的，再向里
走就是衙门大堂了。
。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"jingzhonglu2",
                "north" : __DIR__"yamendatang",
        ]));
/*
        set("objects", ([
                __DIR__"npc/xunbu" : 1,
        ]));
*/
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
