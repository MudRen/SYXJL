// Room: /u/cuer/emei/beilang1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǧ���ֱ��ߵĻ��ȣ������Ŷ��Ⱥ���Ƹ󣬳�����������������
������ǧ���ֵ��ŷ��������Ϳ��Ե���Ƹ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shendeng",
  "east" : __DIR__"beilang2",
]));
	set("no_clean_up", 0);

	set("coor/x",-30);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
