// Room: /d/chang'an/eastgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�����ǳ����ǵĶ����ŵ��ڳ��ţ�ֻ�������Ϸ����������֡�"HIG"

                       ��    ��    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ��̲��ʮ���ϸ��ˡ��������ϳ�ͷ��ʯ
�ף��������������\n"
 );
        set("outdoors", "chang'an");

	set("exits", ([
		"southup" : __DIR__"walle1",
		"northup" : __DIR__"walle2",
		"west"    : __DIR__"dongdajie1",
		"east"    : __DIR__"eastgate2",
	]));
	setup();
	replace_program(ROOM);
}

