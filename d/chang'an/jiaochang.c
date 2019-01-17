// Room: /chang'an/jiaochang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "校场");
        set("long", @LONG
你走进校场，气氛活跃极了，不时便有一阵阵喧闹之声。几名穿着一
身短打的武生正在场子里举着石锁。监考官是一名武将，一身铁甲，到提
扑刀，威风八面。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"shajinqiao2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}