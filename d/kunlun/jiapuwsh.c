// room: /kunlun/jaipuwsh.c

inherit ROOM;



void create()

{

        set("short", "家仆卧室");

        set("long", @LONG

这里是三圣堂家仆的卧室, 陈设粗糙简单。两边靠墙是长长的大通铺，

几十名扫地做饭的家仆都在这里休息。

LONG

        );

        set("exits", ([

                "west" : __DIR__"zoul_4",

        ]));



        setup();

        replace_program(ROOM);

}



