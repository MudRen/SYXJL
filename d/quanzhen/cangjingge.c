// cangjingge.c �ؾ���

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ؾ���");
	set("long", @LONG
��ǰһ��С¥��ɽ����,¥�����������滨��ݣ�������ʿ�ֽ�����
�߶����������������Ҫ��֮һ�Ĳؾ���
LONG
	);

	set("exits", ([
		"west" : __DIR__"houyuan",
             "enter" :__DIR__"cangjingge1",	
          ]));

	set("coor/x",-80);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",280);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}
