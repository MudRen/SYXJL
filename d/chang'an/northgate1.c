// Room: /d/chang'an/northgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
  "�����ǳ����ǵı����ŵ��ڳ��ţ�ֻ�������Ϸ����������֡�
"HIB"
                    ��    ��    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ���ʼ�̲��ʮ���ϸ��ˡ��������ϳ�ͷ
��ʯ�ף����Ͻ��������\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"eastup" : __DIR__"walln1",
		"westup" : __DIR__"walln2",
		"south"  : __DIR__"beidajie1",
		"north"  : __DIR__"northgate2",
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

