// wdroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	һ���ӿ����ݵ���·������������ͨ��ɽ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southeast" : __DIR__"hsroad2",
		"north" : __DIR__"sexit",
	]));

	set("coor/x",-10);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",60);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

