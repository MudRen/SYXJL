#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬������һ�㵡���������ǳ��ȵ�
���졣
long);
         set("exits", ([
             "east" : __DIR__"cl1",
             "north" : __DIR__"qianyuan",
]));
         set("coor/x",90);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}