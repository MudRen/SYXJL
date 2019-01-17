// Room: /chang'an/yaopu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "药铺");
        set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百
个小抽屉里散发出来的。一名郎中独坐在茶几旁，独自喝着茶，看也不看
你一眼。一名小伙计站在柜台后招呼着顾客。柜台上贴着一张已经发黄的
广告(guanggao)。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"yaowangdong",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}