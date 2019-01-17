// Room: /city2/di_anmen.c

#include <room.h>

inherit ROOM;


void create()
{
	set("short", "�ذ���");
	set("long", @LONG
������ǵذ��Ź㳡����ɫ�ĳ�ǽ������ׯ������֮�У�����
�Ͼ��ǻʹ����š���ǰ����С�ţ�һ�����Ǻ��ƳǶ�����Խ��С��
������ȥ���Ͻ��ǵ������淢�Ե���ΰ�ߴ�һ����ֱ�Ĵ�����
�����������ǵذ��Ŷ��֣������ǵذ������֡�����ͨ�������š�
LONG
	);

	set("exits", ([
		"south" : "/d/city2/hbridge",
		"north" : "/d/city2/anding",
		"west" : "/d/city2/di_an3",
		"east" : "/d/city2/di_an2",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "city2");
	set("coor/x",-90);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
