
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ����������רΪ���ݴ�����ֱ�ӵ������õġ�
LONG
	);

	set("exits", ([
		"southwest" :  __DIR__"aobai10",
		"northeast" : __DIR__"aobai12",
	]));
	set("coor/x",-80);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
