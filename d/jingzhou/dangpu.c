
// Room: /jingzhou/dangpu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "当铺");
        set("long", @LONG
这是一家看起来十分普通的当铺，一个五尺高的柜台挡在你的面前，
柜台上放着一块烫金牌子（paizi)，不过看起来已经不在金光闪闪了，想必
很长时间没有搽洗过。柜台后坐着老板，一双精明的滴溜溜地打量着你。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"nanmendajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}