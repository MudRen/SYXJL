// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��ϱ�ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"hsroad2",
		"south" : "/d/city/beimen",
                 "west" : "/d/wuguan/wuguangate1",
	]));

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

