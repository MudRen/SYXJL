#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
���ǹ���ׯ�ĺ�����Ժ�а��ż��������ˣ��Ǹ��һ������������õġ�
������һ����Ժ����������Կ���̫����������ɫ��
LONG
	);
    set("exits", ([
     "north" :__DIR__"gui-out",
     "south" :__DIR__"dayuan" ,
]));

    set("objects", ([
        __DIR__"npc/jiguan" : 2,
    ]) );
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
