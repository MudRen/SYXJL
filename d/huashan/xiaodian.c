// Room: /huashan/jiulou1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
�����ǻ�ɽɽ����һ��С�꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο͵�Ǯ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"square",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}

