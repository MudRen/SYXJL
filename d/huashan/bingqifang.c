// bingqifang.c ������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	�����ǻ�ɽ�ɵı����������ܷ��⼸�������ܣ������ǻ�ɽ�ɸ�
����ƽʱ�����õ��񽣡�
LONG
	);
	set("exits", ([
		"west" : __DIR__"square",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 4]));

	set("no_fight", 1);
	
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	set("coor/x",90);
	set("coor/y",100);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}