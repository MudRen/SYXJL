// room: /kunlun/dalgf_2.c

inherit ROOM;



void create()

{

        set("short", "大练功房");

        set("long", @LONG
这是功力较深的昆仑弟子打坐读书的地方, 只见室内窗明几净, 除了
几个蒲团别无它物。墙上正中有铁琴先生手书的一个大字 ---- "勤", 显
是勉励门下弟子之意。东面是男弟子休息的卧室。
LONG

        );



        set("exits", ([

                "east" : __DIR__"woshi_m",

                "west" : __DIR__"ceting_e",

        ]));

        set("objects", ([

                "/d/kunlun/obj/zhujian" : 2]));



        setup();

        replace_program(ROOM);

}



