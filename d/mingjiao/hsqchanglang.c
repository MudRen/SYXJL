//HSQCHANGLANG.C

inherit ROOM;

void create()
{
	set("short", "��ˮ�쳤��");
	set("long", @LONG
��������һ������֮��, ������������, �������续����. 
С�Ӵ����¾�������, ����֮��Ʈ���ŵ���������, ������ɴ.
���������־����������, �ƺ�û��һ������.
LONG
	);

	set("exits", ([
		"north" : __DIR__"hsqting",
		"out" : __DIR__"hsqmen",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}