// Room: /city/duchang.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���ݶĳ�");
	set("long", @LONG
	�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ�����
���ߺ��ϱ��Ƕġ����ӡ��ķ��䣬�����Ƕġ��ƾš��ķ��䡣¥����
����ĵط���ǽ������(bian)һ�顣
LONG
	);

	set("item_desc", ([
		"bian" : HIG"Ը�ķ���\n"NOR,
	]));
	set("exits", ([
// "north" : __DIR__"dice1",
//                    "enter" : __DIR__"dice2",
                  "up" : __DIR__"duchang2",
		  "east" : __DIR__"nandajie1",
	]));
	set("objects", ([
                "/quest/quest/wuqing": 1,
	]));

	set("no_fight",1);
        set("no_sleep_room", 1);
        set("no_steal", 1);
        set("no_beg", 1);
	set("no_yun",1);
	
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "north" || dir == "south") && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");
        return ::valid_leave(me, dir);
}

