#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
�������һ��С������ͷ��һ��Ů���õ���ױ̨���������������֬��
�С�������һ�ų����ĺ�ľ������ֻҪ̧����ȥ��̫��������̲�����
���۵ס�
long);
         set("exits",([
             "north" : __DIR__"xiaoting",
]));
        set("coor/x",170);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}