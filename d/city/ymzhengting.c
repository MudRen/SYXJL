// Room: /city/ymdongting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	���϶����������ס������һ������������������ϸ������ǽ������һ����
�ң����顰����������ĸ���������Ĵ��֡�֪���������İ����������飬ʦү����
�ں�
LONG
	);

         set("no_fight", 1);

         set("no_yun", 1);
	set("exits", ([
		"east" : __DIR__"dongting",
		"west" : __DIR__"xiting",
		"north" : __DIR__"neizhai",
		"south" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/cheng" : 1,
		__DIR__"npc/shiye" : 1,
	]));

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

