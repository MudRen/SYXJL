//gebi

inherit ROOM;

void create()
{
	set("short", "���");
	set("long",
	     "�������ٽ�ɳĮ�ĸ��̲���������̡�������һ���޼ʵĴ�ɳĮ��\n"
	 "���������Կ���һ��С��\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"east" : "/d/xingxiu/shamo4",
		"northwest" : __DIR__"dongjie",
	]));
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-80);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
