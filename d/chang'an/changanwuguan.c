// Room: /d/chang'an/jiangjunfu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "������");
	set("long", 
"������Ƕ��������ĳ�������ˣ�ֻ����¥�����������������̽��
��д���ĸ�����:"HIY"
����������            ��  ��  ��  ��
"NOR"
    �ſ�վ��һλ��������Ĵ󺺽Ӵ���ǰ��ѧ��ѧ�յ�ѧͽ��ԭ������
�����Ծ��ݸ����˷��ơ�\n"
 );
//        set("outdoors", "chang'an");
	set("exits", ([
		"south" : __DIR__"chongwujie",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/junshi" : 2,
	]));
	setup();
	replace_program(ROOM);
}

