// Room: /d/chang'an/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "��ȸ����");
	set("long", 
"�����ǳ����ǵ��ϳ��ţ�ֻ�������Ϸ����������֡�"HIR"

                       ��    ȸ    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ���ʼ�̲��ʮ���ϸ��ˡ������Ǻܴ��
�ݵء�\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
                "north"  : __DIR__"southgate1",
	]));
/*
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
*/
	setup();
	replace_program(ROOM);
}

