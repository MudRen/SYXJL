// Room: /d/quanzhou/qzroad3.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻���
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad2",
                "east" : __DIR__"qzroad4",
	]));

	set("outdoors", "quanzhou");
	set("coor/x",60);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

