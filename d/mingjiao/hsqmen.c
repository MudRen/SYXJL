//HSQMEN.C

inherit ROOM;

void create()
{
	set("short", "��ˮ�����");
	set("long", @LONG
���������̺�ˮ��Ĵ���, ׯ�Ϲ���, ��ǰ�Բ����������
������ǰˮ������, ȴ��һ��ˮ������������, �����ٲ�����Դ,
ԭ��, ������ˮ��ͽ���������С��֮��.
LONG
	);

	set("exits", ([
		"enter" : __DIR__"hsqchanglang",
		"south" : __DIR__"tohsq7",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",60);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}