// Room: /d/quanzhou/qzroad2.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ�����
���ɫ���Ͳ˻��������ǽ������Ǽ��ˡ������߱���̫��
�ˡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad1",
                "east" : __DIR__"jiaxing",
		"south" : __DIR__"qzroad3",
                "west" : "/d/taohua/taihu",
	]));

	set("outdoors", "quanzhou");
	set("coor/x",60);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

