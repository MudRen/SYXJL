// shanmen.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "������ɽ��");
                  set("long",@long
��һ·���������ܴ���ɳ֮�࣬������ľ������������ʱ������֦Ҷ
�д�����������·�߲ݴ�ż��Ҳ�ܷ���һЩ���ŵ�Ұ�����������������
���컨��ʮ��ïʢ��������û�뵽��ɽ��ȴ��������ڣ������Ϊһ��ǰ
����һ��ɽ�ţ�д�š������ɡ��������֡�
long);
                 set("exits",([
         "north" : __DIR__"damen",
"southdown" : __DIR__"klshanlu",
]));
set("objects",([
        "/d/kunlun/npc/xihuazi.c" :  1,
]));

set("outdoors", "����");
set("coor/x",-180);
	set("coor/y",40);
	set("coor/z",30);
	set("coor/x",-180);
	set("coor/y",40);
	set("coor/z",30);
	set("coor/x",-180);
	set("coor/y",40);
	set("coor/z",30);
	setup();
replace_program(ROOM);
}

