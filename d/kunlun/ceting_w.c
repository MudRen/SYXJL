// room: /kunlun/ceting_w.c

inherit ROOM;



void create()

{

        set("short", "������");

        set("long", @LONG

����һ�������Ĳ�����Ҳ�����ŷ��˴��ڵ������书�ĵط�����������

���˰����ԭ������������ʦ�, �书���ڲ���֮�䡣�ʴ����˷ֱ���ͽ�

�������������ķԸ�, ���ڰڷ��˼��軨��, ȴ�����Ʋ��ã����������

����ϲ����, ����Ҳ���ֵò�ȥ�չˣ�������һ��С���䡣�

LONG

        );



        set("exits", ([

                "north" : __DIR__"xlgf_1",

                "west" : __DIR__"dalgf_1",

                "east" : __DIR__"dating",

        ]));



        setup();

        replace_program(ROOM);

}



