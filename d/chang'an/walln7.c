// Room: /d/chang'an/walln7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
�����ǳ����ı���ͷ��һЩ��ʿ���ڳ�ͷѲ�ߣ�һ������
�������������ܸ����سǲ��ϣ�һЩ���������鹭�������
�ų��µĶ�����
LONG );
        set("outdoors", "chang'an");

	set("exits", ([
		"southeast" : __DIR__"walle8",
		"westdown"  : __DIR__"walln5",
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
