// Room: /d/chang'an/southgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��ȸ����");
	set("long", 
"�����ǳ����ǵ��ϳ��ŵ��ڳ��ţ�ֻ�������Ϸ����������֡�
"HIR"
                      ��    ȸ    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ��̲��ʮ���ϸ��ˡ��������ϳ�ͷ��ʯ
�ף��򱱽��������\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"eastup" : __DIR__"walls2",
		"westup" : __DIR__"walls1",
		"south"  : __DIR__"southgate2",
		"north"  : __DIR__"nandajie1",
	]));
	setup();
	replace_program(ROOM);
}

