// Room: /d/chang'an/wallw8.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
�����ǳ���������ͷ��һЩ��ʿ���ڳ�ͷѲ�ߣ�һ������
�������������ܸ����سǲ��ϣ�һЩ���������鹭�������
�ų��µĶ�����
LONG );
        set("outdoors", "chang'an");

	set("exits", ([
		"southeast" : __DIR__"walls7",
		"northdown"  : __DIR__"wallw6",
	]));
/*
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
*/
	setup();
	replace_program(ROOM);
}