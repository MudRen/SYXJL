// Room: /d/quanzhou/bamboo.c


#include <room.h>
inherit ROOM;


void create()
{
	set("short", "�������ͥ");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ
��ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ�
���Ǿ��ѵ��������ڡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"qinglong",
	]));

//    set("objects",([
//	    __DIR__"npc/tang3" : 1,
//    ]));
//    set("no_clean_up", 1);

	set("coor/x",10);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);

}

