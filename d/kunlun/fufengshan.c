// fufengshan.c (kunlun)



#include <ansi.h>

#include <room.h>

inherit ROOM;



int do_climb();



void create()

{

                  set("short", "����ɽ");

                  set("long", @LONG

һ����ɽ�����������ǰ����������������ķ���ɽ�ˡ�����ɽ������

ʮ�ֶ��ͣ�ɽ�����Ͼ�û��ãã�ƺ����嶥�����ѩ��ɽ������ȴ��������

�ԣ���ľï�ܣ����Ž��أ����������������ò�Զ���������ﴫ��һ������

���������·���ʲô�������������ӡ�

LONG

                  );

                  set("outdoors", "kunlun");



                  set("exits", ([

                                         "enter" : __DIR__"houyuan.c",

                                         "northeast" : __DIR__"bainiushan.c",

                  ]));



                  set("objects",([

                "/d/kunlun/npc/gaozecheng.c" :   1,

                "/d/kunlun/npc/jiangtao.c" :   1,

                ]));

                  set("no_clean_up",0);

create_door("enter", "С��", "out", DOOR_CLOSED);



                  setup();

}



void init()

{

                  add_action("do_climb", "climb");

}

int do_climb()

{

                  object me= this_player();



                   if( random((int)me->query_skill("dodge",1))<=30) {

                                         me->receive_damage("qi", 50);

                                         me->receive_wound("qi", 50);

                                         message_vision(HIR"$Nһ��С�Ľ���̤�˸���... ��...��\n"NOR, me);

                                         me->move(__DIR__"fufengshan.c");

                                         tell_object(me,

                  HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);

                                           message("vision",HIR"ֻ��" + me->query("name") +

                      "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), ({me}));

                return 1;

                  }



                                         message("vision",

                me->name() + "��һ������������������£�������ɽ�ϱ�ȥ��\n",

                                         environment(me), ({me}) );

           me->move(__DIR__"sanshengao.c");

                                         return 1;

}




