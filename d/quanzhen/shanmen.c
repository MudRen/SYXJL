// shanmen.c ȫ��ɽ��

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
        һ���ߴ���Ʒ������������ǰ������һ����ҿ��������̽��
�֡�ȫ��̡����Ʒ�����վ�ż����ֽ���ȫ����ӡ�������ȫ��̹㳡��
LONG);
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"shijie4",
                "northup" : __DIR__"tyroad1",
        ]));

        set("objects", ([
                __DIR__"npc/daoshi" : 2, 
   ]));
 
        set("coor/x",-90);
	set("coor/y",200);
	set("coor/z",160);
	set("coor/x",-90);
	set("coor/y",200);
	set("coor/z",160);
	set("coor/x",-90);
	set("coor/y",200);
	set("coor/z",160);
	set("coor/x",-90);
	set("coor/y",200);
	set("coor/z",160);
	setup();
        replace_program(ROOM);
}
