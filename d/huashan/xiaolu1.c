// xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "Сɽ·");
	set("long", @LONG
�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô�վ���
������������ܾ����ĵģ�������߽���һ��������Դ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"yunu",
		"northeast" : __DIR__"xiaolu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}