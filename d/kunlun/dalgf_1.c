// room: /kunlun/dalgf_1.c

inherit ROOM;



void create()

{

        set("short", "��������");

        set("long", @LONG
���ǹ�����������ص��Ӵ�������ĵط�, ֻ�����ڴ�������, ���˼�
�����ű������ǽ���������������������һ������ ---- "��", ������
�����µ���֮�⡣������Ů������Ϣ������.
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



