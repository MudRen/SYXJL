// shanlu2.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "����ɽ·");
		  set("long",@long
���н���������һ������һ�죬����������������ǿ����;������ʲôǿ
����ֻ�ǻ�ɳ���棬����͸�ǣ�ȴҲ��ʵ�Ѱ���
long);
		 set("exits",([
"eastdown" : __DIR__"shanlu1",
"southup" : __DIR__"bayankala",
]));
set("outdoors", "����");
set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",10);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",10);
	setup();
replace_program(ROOM);
}
