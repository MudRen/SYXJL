// bingqif.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������һ��Сʯ�ݣ������Ǵ�������ģ��������и����¯
���̵��أ����л���һ��ʯ�����������һЩ�Ѿ�����õı�����
LONG
	);
	set("exits", ([
		"south" : __DIR__"xiaodao2",
]));
	set("no_clean_up", 0);
	set("objects", ([
		       __DIR__"obj/blade": 2,
]));
	set("coor/x",-20);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
