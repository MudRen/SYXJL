// room: /kunlun/woshi_m.c

inherit ROOM;



void create()

{

        set("short", "�е�������");

        set("long", @LONG

���������е��ӵ�ס��. �ź��м����³�, ����ȴ�ǰ뿪��, ���Ҷ�

��һ�Ѱ������������м�ֻ���ҵ�Ь��. ��ǽ��������ľ��, ֻ����

��������, ���������Ժ�����߽�������е�������˯����

LONG

        );



        set("exits", ([

                "west" : __DIR__"dalgf_2",

        ]));



          set("sleep_room",1);

            set("no_fight",1);

        setup();

        replace_program(ROOM);

}



