// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���
LONG
	);

	set("exits", ([
		"east" : __DIR__"ml6",
		"west" : __FILE__,
		"south" : __DIR__"dongmen",
		"north" : __FILE__,
	]));
	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
