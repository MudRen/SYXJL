// room: /kunlun/ceting_e.c

inherit ROOM;



void create()

{

        set("short", "������");

        set("long", @LONG

����һ�������Ĳ�����Ҳ�������������ڵ������书�ĵط���������

�ŷ��˰����ԭ������������ʦ�, �书���ڲ���֮�䡣�ʴ����˷ֱ���

ͽ����������ϲ�û���, ������м��衣���ᵽ�˵�����������ÿ����ר

�ŵĻ������չ˺��޼����ǡ�

LONG

        );



        set("exits", ([

                "west" : __DIR__"dating",

                "east" : __DIR__"dalgf_2",

        ]));



        setup();

        replace_program(ROOM);

}



