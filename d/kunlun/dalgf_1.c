// room: /kunlun/dalgf_1.c

inherit ROOM;



void create()

{

        set("short", "大练功房");

        set("long", @LONG
这是功力较深的昆仑弟子打坐读书的地方, 只见室内窗明几净, 除了几
个蒲团别无它物。墙上正中有铁琴先生手书的一个大字 ---- "勤", 显是勉
励门下弟子之意。西面是女弟子休息的卧室.
LONG

        );



        set("exits", ([

                "west" : __DIR__"woshi_f",

                "east" : __DIR__"ceting_w",

        ]));

        set("objects", ([

                "/d/kunlun/obj/zhujian" : 2]));



        setup();

        replace_program(ROOM);

}



