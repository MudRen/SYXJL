// room: /kunlun/zoul_5.c

inherit ROOM;



void create()

{

        set("short", "����");

        set("long", @LONG

����һ�������ĵ�����, ż�������Ů����ʹҴ�ææ���߹���������

��, ���������˾�ס�����پ�����ͨ���Ӳ��ô���, �ǲ��������ڵġ���

����Իص�����.

LONG

        );

        set("exits", ([

                "north" : __DIR__"tieqinju",

                "south" : __DIR__"dating",

        ]));



        setup();

        replace_program(ROOM);

}



