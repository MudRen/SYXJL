
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�������ԶԶ�ľͿ������������ǡ�
LONG
	);

	set("exits", ([
		"northwest" : "/d/city2/road5",
		"southeast" : __DIR__"road7",
	]));
 	set("outdoors", "city2");
	set("coor/x",-20);
	set("coor/y",190);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



