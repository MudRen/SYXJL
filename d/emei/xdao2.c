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
  "north" : __DIR__"shkrkou",
  "east" : __DIR__"xdao1",
]));
	set("no_clean_up", 0);

	set("coor/x",-90);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
