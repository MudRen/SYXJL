// shulin6.c
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","����");
       set("long", @LONG
����һƬټ������֣���ľ���죬���α��գ����������ʧ�˷���
��֪�������Լ����ںδ������в�ʱ����Ұ�޵ĵͺ�,�͹����Х������
����ë���Ȼ��ֻ������뿪��
LONG
     );

    
        set("exits", ([
                 "east" : __DIR__"shulin7",
                "south" : __DIR__"shulin"+(random(10)+2),
                "west" : __DIR__"shulin"+(random(10)+2),
                "north" : __DIR__"shulin5",        ]));             
        set("coor/x",-180);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-180);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-180);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-180);
	set("coor/y",100);
	set("coor/z",0);
	setup();
            replace_program(ROOM);
}

