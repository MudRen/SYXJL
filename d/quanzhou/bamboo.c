// Room: /d/shaolin/zhulin2.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ����������
���ܵ����֡������˼�������Ω�����ߵ��·�棬΢�紵����
Ҷ�����˳���Ϊ֮һ�ӡ��������ľ�֮�⣬ȴ�����й�ɱ����
����������֮�У�������������һ����
LONG
	);

	set("exits", ([
		"west" : __DIR__"qinglong",
//		"west" : __DIR__"qinglong",
//       "south" : "/u/chenww/tianlongbang/road1",
		"north" : __DIR__"nanmen",
	]));

	set("outdoors", "quanzhou");
	create_door("west","ľ��","east",DOOR_CLOSED);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



