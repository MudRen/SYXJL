// baoquan.c ��Ȫ 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
����������ɽ��ɽ������������ζ�����ᣬ���ܷ羰�续������
����һȪ�ۣ�����ˮ�ݲ裬��������һ���������˳���Ϊ��Ȫ�������
Ҳ��������һƷ�����֮�ѵء������Ƕ��ɸ�
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : "/d/gumu/lyy",
                "east" : __DIR__"dusongge",
        ]));
        set("objects", ([
                "d/wudang/npc/monkey" : 1, 
   ]));

        set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",100);
	set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",100);
	set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",100);
	set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}


