// Room: /d/quanzhou/jxnanmen.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǽ��˵����š���Χ����ï�ܵ����֡������������
���Ͽ��븣����
LONG
	);

	set("exits", ([
                "north" : __DIR__"jiaxing",
                "east" : __DIR__"tieqiang",
		"south" : __DIR__"qzroad4",
	]));

        set("outdoors", "����");
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

