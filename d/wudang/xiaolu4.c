// xiaolu4.c С��
// by arnzh

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
	������һ��С���ϣ������ǹ�ͺͺ��ɽ�ڣ�������������һ˿������
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaochidian",
		"east" : __DIR__"shiliang",
	]));
	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",120);
	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",120);
	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}

