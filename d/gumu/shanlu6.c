// shanlu6.c By csy 98/12



inherit ROOM;

#include <ansi.h>

void create()

{

    set("short", YEL"山路"NOR);

    set("long", @LONG

此处是一条崎岖山路，你睁大了眼四下眺望，惟见云生谷底，雾迷峰巅，

空山寂寂，微闻鸟语，天地茫茫，就只你一人而已。又行良久，来到一个大山

洞前。

LONG

        );



    set("exits", ([ 

                "enter"  : __DIR__"shandong",

                "southdown"  : __DIR__"shanlu5",        

    ]));



    set("outdoors", "古墓");



    setup();

}



