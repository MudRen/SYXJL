#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��Ժ");
	set("long", @LONG
����ɽׯ�ĺ�Ժ��Ժ�а��ż��������ˣ��Ǹ��һ������������õġ�
Ժ�����һ�����Ψһһ��ɽ�壺��ָ�塣�����һ�ɽׯ��ɽ������������
�ɡ�
LONG
	);
    set("exits", ([
     "north" :__DIR__"dating",
     "west" :__DIR__"xiaowu",
     "east" :__DIR__"siguoshi" ,
        "south" :__DIR__"tanzhi",
]));

    set("objects", ([
        __DIR__"npc/jiguan" : 2,
    ]) );
	set("coor/x",50);
	set("coor/y",-240);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}