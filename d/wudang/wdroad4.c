// wdroad4.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ����ܾ����ĵġ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : "/d/xiaoyao/shulin3",
		"south" : __DIR__"wdroad5",
		"north" : __DIR__"wdroad3",
	]));

	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

