
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ܶ������ܵ����֣�һ̤�������������·�������˼�������
Ω����̤��ƺ֮����ż����΢�������Ҷ�������������������˳�
��Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG
	);

	set("exits", ([
		"northeast" : __FILE__,
		"southwest" : __FILE__,
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"zhulin4",
		"north" : __DIR__"xiaoyuan.c",
	]));

	create_door("north","����","south",DOOR_CLOSED);
	set("outdoors", "city2");
	set("coor/x",-30);
	set("coor/y",220);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



