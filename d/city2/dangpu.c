// Room: /city2/dangpu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ��
��̨�ϰ���һ������(paizi)����̨�����ż��ϰ壬һ˫�������۾�����
���´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_study", 1);
	set("no_beg",1);
        set("no_steal",1);
        set("no_yun",1);

	set("item_desc", ([
		"paizi" : "\n��ƽ����\n",
	]));
	set("objects", ([
		"/d/city2/npc/jia" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandaj1",
	]));

	set("coor/x",-60);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

