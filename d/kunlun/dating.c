// room: /kunlun/dating.c

inherit ROOM;



void create()

{

        set("short", "大厅");

        set("long", @LONG

这是三圣堂的大厅，历来是掌门人正式待客的地方，故此陈设庄重谨严。�

正中有两张太师椅，是掌门人及夫人的座位。室内一尘不染, 异常整洁。几

名弟子低头侍立在一旁，东西两边各有一个侧厅，厅上高高的悬一幅巨大的

匾额 (bian)。

LONG

        );

        set("item_desc", ([

                "bian"    : "上书四个大字“琴 剑 无 双”\n",

        ]));

        set("exits", ([

                "south" : __DIR__"zhongt",

                "north" : __DIR__"zoul_5",

                "west" : __DIR__"ceting_w",

                "east" : __DIR__"ceting_e",

        ]));



        setup();

        replace_program(ROOM);

}



