// room: /kunlun/zoul_5.c

inherit ROOM;



void create()

{

        set("short", "走廊");

        set("long", @LONG

这是一条静悄悄的走廊, 偶尔看见婢女或家仆匆匆忙忙地走过。从这里

向北, 就是掌门人居住的铁琴居了普通弟子不得传唤, 是不能再向内的。南

面可以回到大厅.

LONG

        );

        set("exits", ([

                "north" : __DIR__"tieqinju",

                "south" : __DIR__"dating",

        ]));



        setup();

        replace_program(ROOM);

}



