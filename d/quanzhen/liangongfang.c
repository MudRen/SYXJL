// liangongfang.c ������
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ���λȫ���������ϥ������
�������
LONG
	);
	set("exits", ([
		"east" : __DIR__"xilang3",
	]));
	
	set("no_fight", 1);
	
	set("coor/x",-110);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",260);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}
