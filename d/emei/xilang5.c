
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǧ���ֱ��ߵĻ��ȣ������Ⱥͱ��ȵĽ��㴦����������������
����������ǧ���ֵı����ţ������Ϳ��Ե���Ƹ��ˡ�				
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"beicemen",
  "south" : __DIR__"xilang4",
  "east" : __DIR__"beilang",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
