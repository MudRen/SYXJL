// Room: /d/gaibang/undertree.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;









void create()

{

        set("short", "������");

	set("long", @LONG

�����һ��������Աߵ�С���������������õģ������˸�������   
������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����

LONG

	);



	set("exits", ([

               "out" : "/d/taohua/dating",

               "east":__DIR__"ttaohua2",

	]));



	set("objects",([

                  CLASS_D("gaibang") + "/li-fu" : 1,

	]));



	setup();

	replace_program(ROOM);

}







