inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�������ͨ���߿ߵ�С������խ��С�������������졣·�������Ӳݴ�
����ż������������´ܹ�������������ʪ�����ǳ��������ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xdao2",
  "east" : __DIR__"beicemen",
]));
	set("no_clean_up", 0);

	set("coor/x",-80);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
