// Room: /city/xidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
	����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����
ϡ�٣������ĵغ������塣������һ�����ֵĹ㳡���ϱ��Ǳ�Ӫ�����߾��������ˡ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"guangchang",
		"south" : __DIR__"bingyindamen",
		"west" : __DIR__"xidajie2",
		"north" : __DIR__"yamen",
	]));

	set("objects", ([
                __DIR__"npc/newxunbu" : 1,
	]));

	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

