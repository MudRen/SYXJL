// Room: /d/gaibang/xxandao2.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;



void create()

{

	set("short", "����");

	set("long", @LONG

���������޺����¶��Ե�һ��С���������������õģ������˸�����
�����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG

	);



	set("exits", ([

                        "out" : "/d/xingxiu/xxh2",

			"east" : __DIR__"xxandao1",

	]));



	set("objects",([

                CLASS_D("gaibang") + "/huo-du" : 1,
		"/d/city/obj/jitui" : 3,

		"/d/city/obj/jiudai" : 1,

	]));



	setup();

	replace_program(ROOM);

}







