// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"wdroad2",
               "west" : "/d/dali/dadao1",
		"north" : "/d/city/nanmen",
                   "east" : "/d/wenrou-po/shanlu",
	]));

	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

