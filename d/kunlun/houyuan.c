// houyuan.c (kunlun)



#include <ansi.h>

#include <room.h>



inherit ROOM;



void create()

{

                  set("short", "��Ժ");

                  set("long",@long

��������һ�����������������������ǣ�Ҳ�ͺܾ�û�б���ɨ���ˡ���Ҷ

���أ�����ȥ������ġ�ǽ������Щ���ƣ����½�����֩�������������һ��

С����Ϊ��ɹ���ܣ���ʼ���á�������һƬ�����֡�

long);

                 set("exits",([

                          "out" : __DIR__"fufengshan",

                          "south" : __DIR__"shanlin2",

]));



        set("objects", ([ /* sizeof() == 1 */

                "/d/heimuya/npc/tong-ren" : 4,
]));



set("no_clean_up", 0);

create_door("out", "С��", "enter", DOOR_CLOSED);



set("outdoors", "����");

setup();

replace_program(ROOM);

}



