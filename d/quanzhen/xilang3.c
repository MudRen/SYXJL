//xilang3.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ�������ϣ������Ǻ���������������
LONG
	);

	set("exits", ([
	     "west" : __DIR__"liangongfang",
           "east" : __DIR__"houdian",
          ]));
	set("coor/x",-100);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",260);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}
