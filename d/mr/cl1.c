#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬������һ�㵡���������ǳ��ȵ�
���졣���ų�������Կ��������Сʯ�š�
long);
         set("exits", ([
             "east" : __DIR__"cl2",
             "west" : __DIR__"cl",
]));
         set("coor/x",100);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}
