inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�����Ƕ�üɽ��ɽ�ţ�һ��������ʯ�������죬�ϵĽ��������
��������;�������֣�������С����·���򣬻��ж�ü��Ů����׼ҵ���
����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shijie12",
  "northup" : __DIR__"shijie3",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",-60);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",-60);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
