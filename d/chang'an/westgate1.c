// Room: /d/chang'an/westgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�����ǳ����ǵ������ŵ��ڳ��ţ�ֻ�������Ϸ����������֡�"HIW"

                      ��    ��    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ��̲��ʮ���ϸ��ˡ��������ϳ�ͷ��ʯ
�ף��򶫽��������\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"southup" : __DIR__"wallw2",
		"northup" : __DIR__"wallw1",
		"east"    : __DIR__"xidajie1",
		"west"    : __DIR__"westgate2",
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

