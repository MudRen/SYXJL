//RJQMEN.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������һ�����ţ����ֻ�ݵ���һ���˽�����ÿ������
���ˣ��������ʾһ�����ƣ��ſɽ��롣
LONG
	);

	set("exits", ([
		"enter" : __DIR__"rjqyuan",
		"east" : __DIR__"torjq3",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-130);
	set("coor/y",-10);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}