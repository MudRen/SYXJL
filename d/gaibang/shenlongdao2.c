// Room: /d/gaibang/xxandao2.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;



void create()

{

	set("short", "����");

	set("long", @LONG

����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 

LONG

	);



	set("exits", ([

                       "west" : __DIR__"underxxx",

                       "east" : __DIR__"shenlongdao1",

	]));



	set("objects",([

		"/d/city/obj/jitui" : 3,

		"/d/city/obj/jiudai" : 1,

	]));



	setup();

	replace_program(ROOM);

}






