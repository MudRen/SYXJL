inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����������Ĵ���������������У�ʮ�����֡����߾��ǳ����š�
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"west" : __DIR__"wangfu2",
		"east" : __DIR__"chaoyang",
	]));

	set("coor/x",-50);
	set("coor/y",170);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


