// room: /kunlun/ceting_e.c

inherit ROOM;



void create()

{

        set("short", "东侧厅");

        set("long", @LONG

这是一个安静的侧厅，也是铁琴先生传授弟子们武功的地方。当今掌

门夫人班淑娴原是铁琴先生的师姊, 武功亦在伯仲之间。故此两人分别收

徒。铁琴先生喜好花草, 这里摆有几盆。你嗅到了淡淡的香气，每天有专

门的花匠来照顾和修剪它们。

LONG

        );



        set("exits", ([

                "west" : __DIR__"dating",

                "east" : __DIR__"dalgf_2",

        ]));



        setup();

        replace_program(ROOM);

}



