// Room: /d/chang'an/westgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�����ǳ����ǵ������ţ�ֻ�������Ϸ����������֡�"HIW"

                      ��    ��    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ���ʼ�̲��ʮ���ϸ��ˡ������Ǻܴ��
�ݵء�\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"east"  : __DIR__"westgate1",
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

