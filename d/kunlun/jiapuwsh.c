// room: /kunlun/jaipuwsh.c

inherit ROOM;



void create()

{

        set("short", "��������");

        set("long", @LONG

��������ʥ�ü��͵�����, ����ֲڼ򵥡����߿�ǽ�ǳ����Ĵ�ͨ�̣�

��ʮ��ɨ�������ļ��Ͷ���������Ϣ��

LONG

        );

        set("exits", ([

                "west" : __DIR__"zoul_4",

        ]));



        setup();

        replace_program(ROOM);

}



