inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ͨ������ɽ��ʯ�ף�һ��������ʯ���������죬����û�о�ͷ
�Ƶģ��ϵĽ����������������;�������֣�������С����·���򣬻�
�ж�ü��Ů����׼ҵ�������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shijie10",
  "northwest" : __DIR__"shijie12",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
