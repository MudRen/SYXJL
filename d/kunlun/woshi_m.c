// room: /kunlun/woshi_m.c

inherit ROOM;



void create()

{

        set("short", "男弟子卧室");

        set("long", @LONG

这是昆仑男弟子的住处. 门后有几个衣橱, 橱门却是半开的, 胡乱堆

着一堆半脏的衣物。地上有几只零乱的鞋子. 靠墙有三两张木床, 只听得

鼾声如雷, 夹杂着迷迷糊糊梦呓。几名男弟子正在睡觉。

LONG

        );



        set("exits", ([

                "west" : __DIR__"dalgf_2",

        ]));



          set("sleep_room",1);

            set("no_fight",1);

        setup();

        replace_program(ROOM);

}



