// room: /kunlun/dating.c

inherit ROOM;



void create()

{

        set("short", "����");

        set("long", @LONG

������ʥ�õĴ�������������������ʽ���͵ĵط����ʴ˳���ׯ�ؽ��ϡ��

����������̫ʦ�Σ��������˼����˵���λ������һ����Ⱦ, �쳣���ࡣ��

�����ӵ�ͷ������һ�ԣ��������߸���һ�����������ϸ߸ߵ���һ���޴��

�Ҷ� (bian)��

LONG

        );

        set("item_desc", ([

                "bian"    : "�����ĸ����֡��� �� �� ˫��\n",

        ]));

        set("exits", ([

                "south" : __DIR__"zhongt",

                "north" : __DIR__"zoul_5",

                "west" : __DIR__"ceting_w",

                "east" : __DIR__"ceting_e",

        ]));



        setup();

        replace_program(ROOM);

}



