// yuxudong.c ���鶴 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���鶴");
	set("long", @LONG
��ǰ��һ������Ȼ�����˹���ɽ�������ܵ��ż�յ�����ƣ����з���һ�����ӣ���
����⼸���顣�������ҵķ����߸����˴����õ����š������ϸ�Ĺ۲�һ�£���
��е����еİ������ʲô������
LONG
	);
       
	set("exits", ([
		"out" : __DIR__"yadi",
	    ]));
	set("coor/x",-80);
	set("coor/y",320);
	set("coor/z",200);
	setup();
	replace_program(ROOM);
}



