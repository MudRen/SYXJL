//xiuxishi.c ��Ϣ��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
	���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����

LONG
	);

	set("exits", ([
	     "west" : __DIR__"donglang3",
        ]));
           set("sleep_room",1);
	set("coor/x",-70);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",260);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}




