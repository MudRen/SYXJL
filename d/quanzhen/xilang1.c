//xilang1.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������������ϡ�����һ��֧�ڱ���İ��ɵ��ϣ���һ����
�붫���������ݶ����������ȶ��ߵ�ǽ�Ͽ��ŵ������ӵġ����¾�����
�����ǰ��ɵ
LONG
	);

	set("exits", ([
	      "north" : __DIR__"baxiandian",
             "east" : __DIR__"sanqingdian",
	]));
	set("coor/x",-100);
	set("coor/y",250);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",250);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",250);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",250);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}
