// Room: /d/quanzhou/qzroad4.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻���
�����ǽ������Ǽ��ˡ���������븣������ɽ����
LONG
	);

	set("exits", ([
                "north" : __DIR__"jxnanmen",
                "west" : __DIR__"qzroad3",
		"south" : __DIR__"qzroad5",
	]));

	set("outdoors", "quanzhou");
	set("coor/x",70);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

