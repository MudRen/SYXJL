// shijie1.c ʯ��

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
		"westup" : __DIR__"yaotai",
		"east" : __DIR__"shijie2",
	]));
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

