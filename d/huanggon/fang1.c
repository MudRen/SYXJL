
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ��С�ݣ�һ��̫��������Ϣ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"zoulang1",
	]));
	set("objects", ([
		"/d/huanggon/npc/taijian":1,
	]));

	set("coor/x",-60);
	set("coor/y",190);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



