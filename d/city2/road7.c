
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG
	);

	set("exits", ([
		"northwest" : "/d/city2/road6",
		"east" : __DIR__"road4",
	]));
		set("objects", ([
	"/d/huashan/npc/haoke" : 1,
	]));
 	set("outdoors", "city2");
	set("coor/x",-10);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



