//HSQTING.C

inherit ROOM;

void create()
{
	set("short", "��ˮ�����");
	set("long", @LONG
�����Ǻ�ˮ��Ĵ���, 
LONG
	);

	set("exits", ([
//		"enter" : __DIR__"hsqchanglang",
		"south" : __DIR__"hsqchanglang",
	]));

//	set("outdoors", "mingjiao");
	setup();
//	replace_program(ROOM);
}