//dongkou

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
	     "������ɽ�������ѵĶ��ڣ��ر�ɭ�ϡ�\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongnei",
		"south" : __DIR__"xiaolu4",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 2,
	]));

	set("coor/x",-80);
	set("coor/y",-20);
	set("coor/z",-10);
	set("coor/x",-80);
	set("coor/y",-20);
	set("coor/z",-10);
	set("coor/x",-80);
	set("coor/y",-20);
	set("coor/z",-10);
	set("coor/x",-80);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}
