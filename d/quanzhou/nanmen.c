// Room: /d/quanzhou/nanmen.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "Ȫ������");
	set("long", @LONG
�������Ϸ���һ��Ȫ�ݵ����š���������һƬ��Ұ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"bamboo",
                "north" : __DIR__"zhongxin",
	]));

	set("outdoors", "quanzhou");
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

