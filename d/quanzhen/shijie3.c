// shijie3.c ʯ��

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ����
�ͱڣ�һ�������£�̧ͷ��Լ�ɼ������������е�ɽ�壬������ˮ��
�ȣ������Ŀ�������
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"yuqingchi",
                "northup" : __DIR__"shijie4",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/guest" : 2, 
   ]));
        set("coor/x",-90);
	set("coor/y",180);
	set("coor/z",140);
	set("coor/x",-90);
	set("coor/y",180);
	set("coor/z",140);
	set("coor/x",-90);
	set("coor/y",180);
	set("coor/z",140);
	set("coor/x",-90);
	set("coor/y",180);
	set("coor/z",140);
	setup();
        replace_program(ROOM);
}

