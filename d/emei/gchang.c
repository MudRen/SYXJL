inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
���곤����ʯ�ף�����һ�������ֵĹ㳡�������Ǳ����´���ǰ�Ĺ�
����������������ı����£���ʱ������ɽ����������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"bgsgate",
  "southdown" : __DIR__"shijie3",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",20);
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",20);
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
