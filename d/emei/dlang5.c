inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǧ���ֶ��ߵĹ����������Ϻܰ�������ʱ���������������ߴ�
����ľ�������̾���������������ʦ̫���������������������������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"chfang12",
  "north" : __DIR__"dlang4",
  "east" : __DIR__"xfang4",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
