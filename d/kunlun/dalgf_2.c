// room: /kunlun/dalgf_2.c

inherit ROOM;



void create()

{

        set("short", "��������");

        set("long", @LONG
���ǹ�����������ص��Ӵ�������ĵط�, ֻ�����ڴ�������, ����
�������ű������ǽ���������������������һ������ ---- "��", ��
���������µ���֮�⡣�������е�����Ϣ�����ҡ�
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



