//TOHSQ6.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ�Ҿ޴���ٲ������������Խɽ�䣬ˮ����Ũ�÷·����
����ˮ�������ɽ�ͼ����𱡱����������۲�ɢ��������ˮ��
���������
LONG
	);

	set("exits", ([
		"north" : __DIR__"tohsq7",
		"south" : __DIR__"tohsq5",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",40);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}