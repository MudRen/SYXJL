inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ͨ��ʦ̫�ǵ������Ĺ��������߾���ǧ���ֵĴ�������ǰ�
����û�������ӵ�������������һ���ŵĻ��ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dadian",
  "east" : __DIR__"dlang3",
]));
	set("no_clean_up", 0);

	set("coor/x",-30);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-30);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
