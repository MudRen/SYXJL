#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ�������ߣ�
ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ��Ҷ�
��������ȥ����æ���Լ������飬������һ�㵡���������������ǳ��ȵ�
���죬�����Ǻ�Ժ��������һ���᷿�� 
long);
         set("exits", ([
              "north" : __DIR__"cl2",
             "east" : __DIR__"houyuan",
             "south" : __DIR__"xiangfang1",
             "west" : __DIR__"c13-1",
]));
         set("coor/x",110);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}
