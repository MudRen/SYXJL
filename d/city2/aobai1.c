// Room: /city2/aobai1.c


inherit ROOM;

void create()
{
	set("short","�ֵ�");
	set("long", @LONG
�������������ݸ��ˣ�˭Ҳ�������Ƕ�ȥ����������������֡�
LONG
	);

	set("exits", ([
		"west" : __DIR__"aobai2",
		"east" : __DIR__"wangfu1",
	]));

	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));

	set("coor/x",-50);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

