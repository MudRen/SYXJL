// donglang3.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ�������ϣ������м������ң��������������֡�
LONG
	);

	set("exits", ([
	     "east" : __DIR__"xiuxishi",
           "west" : __DIR__"houdian",
       ]));

		
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",260);
	set("coor/z",190);
	setup();
       replace_program(ROOM);

}
