
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ģ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG
	);

	set("exits", ([
		"east" : "/d/bhd/haigang",
		"northwest" : __DIR__"road2",
		"south" : __DIR__"road4",
	]));

	set("objects",([
		"/d/taishan/npc/shu-sheng" : 1,
	]));

 	set("outdoors", "city2");
	set("coor/x",10);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



