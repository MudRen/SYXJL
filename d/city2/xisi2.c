inherit ROOM;

void create()
{
	set("short", "���ı����");
	set("long", @LONG
���������ı���֡��ϱ�ͨ������������ͨ��ذ���,������һ����Ժ��
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"south" : __DIR__"xisi",
		"east" : __DIR__"di_an4",
		"north" : __DIR__"shuyuan",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke": 1,
	]));
	set("coor/x",-70);
	set("coor/y",190);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


