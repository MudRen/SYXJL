
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ����Ͼ��Ǳ����ǡ������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·�����������и�С
̯�������������ЪϢ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"road4",
		"south" : __DIR__"road9",
		"west" : __DIR__"xiaotan"		
	]));

	set("outdoors", "city2");
	set("coor/x",0);
	set("coor/y",170);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



