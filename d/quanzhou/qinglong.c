// Room: /d/quanzhou/bamboo.c


#include <room.h>
inherit ROOM;


void create()
{
	set("short", "������ǰͥ");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ
��ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ�
���Ǿ��ѵ��������ڡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"qinglong1",
		"south" : __DIR__"qinglong2",
		"north" : __DIR__"qinglong3",
		"east" : __DIR__"bamboo",
	]));
	
//	set("objects",([
//	    __DIR__"npc/tang" : 1,
//    ]));

	create_door("east","ľ��","west",DOOR_CLOSED);

	set("coor/x",20);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);

}
