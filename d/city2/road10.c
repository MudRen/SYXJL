
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ��С���ϡ����߾��Ǻ�����.
LONG
	);

	set("exits", ([
		"east" : "/d/city2/haigang",
		"west" : "/d/city2/road1",
		"south" : "/d/shaolin/ruzhou",
		"north" : "/d/city2/road9",
	]));

	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));

 	set("outdoors", "city2");
	set("coor/x",0);
	set("coor/y",150);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



