// neishi.c ����

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ҳ����࣬����һ����һ���ţ�һ����������ǽ��д
�Ŵ���һ���������֡�һλ��ü��Ŀ�Ļ����ϵ�������������
�ϴ���������С��ͯվ�ڴ��ߡ�
LONG
        );
       
        set("exits", ([
                "east" : __DIR__"zhongtang",
             ]));

        set("objects", ([
                __DIR__"npc/mayu" : 1, 
   ]));

        create_door("east", "����", "west", DOOR_CLOSED);
        set("coor/x",-120);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",270);
	set("coor/z",190);
	set("coor/x",-120);
	set("coor/y",270);
	set("coor/z",190);
	setup();
        replace_program(ROOM);
}
