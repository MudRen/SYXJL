// Room: /d/gaibang/undertree.c

// Date: Haa 96/03/22



#include <room.h>

inherit ROOM;









void create()

{

        set("short", "������");
	set("long", @LONG

���������̴����µ�һ���ܶ��������������õģ������˸���
�������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ

����

LONG

	);



	set("exits", ([

               "out" : "/d/shenlong/dating",

               "east":__DIR__"shenlongdao2",

	]));



	set("objects",([

		CLASS_D("gaibang") + "/yu-hx" : 1,

	]));



	setup();

	replace_program(ROOM);

}







