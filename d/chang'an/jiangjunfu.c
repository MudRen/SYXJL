// Room: /d/chang'an/jiangjunfu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "������");
	set("long", 
"һ�����ɷǷ��Ĵ�ԺԾ��������ߣ�ֻ����ǽ���ߣ���¥����������
���Է���һֻ�������Ĵ�ʨ�ӣ����ŵ��Ҷ�������������:"HIY"
                        �� �� ��
"NOR"
    һ��ƫ���ͼ�����ʿ������������վ�ڴ��ſڣ�������м����������һ
�ۡ�\n"
 );
        set("outdoors", "chang'an");
	set("exits", ([
		"south" : __DIR__"xidajie3",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/junshi" : 2,
	]));
	setup();
	replace_program(ROOM);
}

