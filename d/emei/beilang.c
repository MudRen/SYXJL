inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǧ���ֱ��ߵĻ��ȣ����������Ⱥ���Ƹ󣬳�����������������
������ǧ���ֵı����ţ������Ϳ��Ե���Ƹ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xilang5",
  "east" : __DIR__"shendeng",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
