// Room: /u/setup/bingshan2.c



inherit ROOM;



void create()

{

        set("short", "��ɽ");

        set("long", @LONG

����һ��ܴ󸡶���ɽ����������������ɡ�����ǰ��ı�ɽ�ܵ���ɽ

֮�ȣ����ϵ��ۻ�������������������ม�����ϵ����������Ա�ɽ�ǲ���

�Ŀ�����ɽ��



LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "out" : __DIR__"bingshan1",

]));

        set("no_clean_up", 0);

         set("objects", ([ /* sizeof() == 1 */

		__DIR__"npc/bingxiong":1,
]));

        setup();

}







void init()

{

        

        add_action("do_jump", "jump");

        add_action("do_jump", "yue");

}



int do_jump(string arg)

{

        object me = this_player();



        if ( arg == "fubing") {

                if (me->query_skill("dodge", 1) >= 60) {

                        message("vision", me->name() + "���˿��������������Ծȥ��\n",

                                environment(me), ({me}) );

                        write("�����˿��������������Ծȥ��\n");

                        me->move(__DIR__"xiaobing");

                        message("vision", "ֻ����Ӱһ����" + me->name() +  "����Ծ�˹�����\n",

                                environment(me), ({me}) );

                        

                        return 1;

                }

                else {

                        message("vision", me->name() + "���������Ծȥ��ֻ������ͨ��һ����" + me->name() + "ˤ����У��Ǳ������˻�����\n",

                                environment(me), ({me}) );

                        write("�����������Ծȥ��ֻ������ͨ��һ������ˤ����У��Ǳ������˻�����\n");

                        me->receive_damage("qi",30);

                        return 1;

                }

        }

        return 0;



}

