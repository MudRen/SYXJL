inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�������������Ƚ���ĵط��������ɵ�ǧ���ִ������Ϳ��Գ���
���ŵ����Ƹ��ˣ�������������ʦ̫�Ǻ��׼ҵ��ӵ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dxiang",
  "south" : __DIR__"dlang4",
  "north" : __DIR__"dlang2",
  "east" : __DIR__"dcmen",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
