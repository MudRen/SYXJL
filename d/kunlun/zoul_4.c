// room: /kunlun/zoul_4.c

inherit ROOM;



void create()

{

        set("short", "����");

        set("long", @LONG

����һ�������ĵ�����, ż���������ӻ���ʹҴ�ææ���߹�. ������

���͵����ң�������������

LONG

        );

        set("exits", ([

                "west" : __DIR__"zhongt",

                "east" : __DIR__"jiapuwsh",

        ]));



        setup();

        replace_program(ROOM);

}



