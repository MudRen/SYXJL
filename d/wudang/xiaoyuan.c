// xiaoyuan.c ��ɽСԺ
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
	���Ǻ�ɽ��һ��СԺ�����ü�򵥵�������һ����һ����һ�Ρ�һ���ţ�
��Ҳû�б��ʲ��Ƚ�����עĿ����ǽ�Ϲ���һ�ѽ�����������䵱��ɽ��ʦ
��������������ڡ���Ϊ�����������᳣ס�ĵط������ǰ����������
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhang" : 1 ]));
	create_door("south", "����", "north", DOOR_CLOSED);
	set("coor/x",-70);
	set("coor/y",210);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",210);
	set("coor/z",230);
	setup();
	replace_program(ROOM);
}

