inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ɽ��С���������˼�������С���������û���ˣ�������
����·������������һ��ɽ������ɽ������������ҩ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ywdong",
  "northwest" : __DIR__"shandao3",
]));
	set("no_clean_up", 0);

	set("coor/x",-10);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
