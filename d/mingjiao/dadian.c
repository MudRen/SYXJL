//room: /d/mingjiao/dadian.c

inherit ROOM;



void init();



void create()

{

        set("short","���̴��");

        set("long", @LONG

�߽����ͻ��һ������֮�⣬�����ʮ�ֿտ����������յ

��ƣ������Ǿ�׳�彣��ʿ����ɭ�ϱ��ˡ�������һ������ǰ��һ��

��̴ľ������ͷ������������(ling)��ö������������һ����������

��������������ʥ��ͼ������ֱ�����¡������϶���һ�ˣ��Ų��¶�

�Ը߹󣬺�Ц��ŭ���������������̽������޼ɡ�

LONG

           );

        set("exits",([

            "south" : __DIR__"qiandian",

           ]));

        set_temp("tieling",8);

        set("objects",([

//			__DIR__"npc/wushi":12,

			"/kungfu/class/mingjiao/zhangwuji":1,

        		"/kungfu/class/mingjiao/yangxiao":1,

		        "/kungfu/class/mingjiao/fanyao":1,

		        "/kungfu/class/mingjiao/yintianzheng":1,

		        "/kungfu/class/mingjiao/xiexun":1,

		        "/kungfu/class/mingjiao/weiyixiao":1,

			]));

        setup();

}

