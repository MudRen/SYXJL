
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǧ���ֶ��ߵĹ����������Ϻܰ�������ʱ���������������ߴ���
��ľ�������̾���������������ʦ̫�������������Ǳ����ǵ�������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"chfang9",
  "south" : __DIR__"dlang2",
  "north" : __DIR__"beilang2",
  "east" : __DIR__"xfang1",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
