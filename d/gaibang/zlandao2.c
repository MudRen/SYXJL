// Room: /d/gaibang/zlandao2.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;



void create()

{

	set("short", "����");

	set("long", @LONG

����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 

LONG

	);



	set("exits", ([

			"northeast" : __DIR__"undergb",

			"southwest" : __DIR__"zlandao1",	

	]));



	set("objects",([

		"/d/city/obj/jitui" : 3,

		"/d/city/obj/jiudai" : 1,

                CLASS_D("gaibang") + "/kuaihuo" : 1,

	]));



	setup();

	replace_program(ROOM);

}






