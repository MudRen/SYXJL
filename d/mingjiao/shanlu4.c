#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
����ɽ·������ʯ��·��̦�۵��࣬·������ΡΡ��·����
��������ԶԶ�ģ�ֻ��ǰ��������ϡ�����ɫ������չ����˵����
�һ����ڴ˾��أ���������������ʯ��
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shanlu3",
		"northup" : __DIR__"lhqpaifang",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-150);
	set("coor/y",-50);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
