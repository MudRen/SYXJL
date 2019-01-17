// room: /kunlun/ceting_w.c

inherit ROOM;



void create()

{

        set("short", "西侧厅");

        set("long", @LONG

这是一个安静的侧厅，也是掌门夫人传授弟子们武功的地方，当今掌门

夫人班淑娴原是铁琴先生的师姊, 武功亦在伯仲之间。故此两人分别收徒�

按照铁琴先生的吩咐, 室内摆放了几盆花卉, 却都长势不好，盖因夫人向

来不喜花草, 家仆也就乐得不去照顾，北面有一个小房间。�

LONG

        );



        set("exits", ([

                "north" : __DIR__"xlgf_1",

                "west" : __DIR__"dalgf_1",

                "east" : __DIR__"dating",

        ]));



        setup();

        replace_program(ROOM);

}



