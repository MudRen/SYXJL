inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������Ƚ���ĵط��������ɵ�ǧ���ִ������Ϳ��Գ���
���ŵ��׶�ƺ��̫��ƺ�����ˣ�������������ʦ̫�ǵ������ˡ�				
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xicemen",
  "north" : __DIR__"xilang3",
  "south" : __DIR__"xilang2",
  "east" : __DIR__"xilang6",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
