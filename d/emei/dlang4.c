inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǧ���ֶ��ߵĹ����������Ϻܰ�������ʱ���������������ߴ�
����ľ�������̾���������������ʦ̫������������������ϼ��������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"chfang11",
  "south" : __DIR__"dlang5",
  "north" : __DIR__"dlang3",
  "east" : __DIR__"xfang3",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
