// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˴�������أ����������ƥ�Ѳ�����ǰ������˵��������
����̩ɽ��������������������ʣ������˰���Ҫ�ĳ�С��
��ɽ��
LONG
	);

	set("exits", ([
		"northup" : __DIR__"ertian",
		"southdown" : __DIR__"shijin",
	]));

	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/jian-ke" : 1,
	]));

	set("outdoors", "taishan");
	set("coor/x",70);
	set("coor/y",70);
	set("coor/z",50);
	set("coor/x",70);
	set("coor/y",70);
	set("coor/z",50);
	set("coor/x",70);
	set("coor/y",70);
	set("coor/z",50);
	set("coor/x",70);
	set("coor/y",70);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}

