// guanyintai.c ����̨ 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����̨�ֳƴ�̨��λ�ڶ��ɸ�֮�ϣ������������ַ��̨�ӽǿ�������
�������˰����ش��������ؽ�Ϊ֮һ�����Ŀ�������
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
	    "southdown" : __DIR__"dusongge",
	    "eastup" : __DIR__"gaoguanpubu",
      	]));
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}



