// shijie2.c ʯ��

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���
LONG
	);
        set("outdoors", "tianlongsi");

	set("exits", ([
		"west" : __DIR__"shijie1",
		"east" : __DIR__"jietan",
	]));
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-110);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

