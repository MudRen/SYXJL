inherit ROOM;

void create()
{
	set("short", "�ƺ����");
	set("long", @LONG
������Ƕ����������ƺ��ˣ�������ȥ����ɽ��Ұ��������������Ū
�����Լ����ںγ�������������ԼԼ��һ��С��ͨ��ǰ�������ǻ�ȥ�ɡ�
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"yunhai0",
  "southeast" : __DIR__"shandao2",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",120);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
