// room: /kunlun/zoul_3.c

inherit ROOM;



void create()

{

        set("short", "����");

        set("long", @LONG

����һ�������ĵ�����, ż���������ӻ���ʹҴ�ææ���߹���������

������������������

LONG

        );

        set("exits", ([

                "west" : __DIR__"chufang",

                "east" : __DIR__"zhongt",

           ]));



        setup();

        replace_program(ROOM);

}



