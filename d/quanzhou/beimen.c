// Room: /d/quanzhou/beimen.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "Ȫ�ݱ���");
	set("long", @LONG
�������Ϸ���һ��Ȫ�ݵı��š��������򱱿ɵ���ԭ��
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad5",
                "south" : __DIR__"zhongxin",
	]));

        set("outdoors", "Ȫ��");
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

