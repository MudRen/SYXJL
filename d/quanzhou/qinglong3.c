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
		"south" : __DIR__"qinglong",
	]));

//    set("objects",([
//	    __DIR__"npc/tang1" : 1,
//    ]));
    set("no_clean_up", 1);
 
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);

}

