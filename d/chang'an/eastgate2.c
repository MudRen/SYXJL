// Room: /d/chang'an/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�����ǳ����ǵĶ����ţ�ֻ�������Ϸ����������֡�"HIG"

                       ��    ��    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ���ʼ�̲��ʮ���ϸ��ˡ������Ǻܴ��
�ݵء�\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"west"  : __DIR__"eastgate1",
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

