
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡��������������������Ͼ��ǡ��ϱ�ͨ������
�ǡ�
LONG
	);

	set("exits", ([
		"north" : "/d/city2/road3",
		"west" : __DIR__"road7",
		"south" : "/d/city2/road8",
	]));

	set("objects",([
		"/d/taishan/npc/jian-ke" : 1,
	]));

 	set("outdoors", "city2");
	set("coor/x",0);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



