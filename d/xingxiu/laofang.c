// laofang.c

// by QingP



#include <ansi.h>



inherit ROOM;



void create()

{

	set("short", "�η�");

	set("long", @LONG

����һ��������ʪ��ɽ����������ɢ����һ����������Ż��

������ζ���ڰ��Ľ����������ż�����Ӱ������ĳ����ƺ�����

֪������������һ���ˣ���ϸ��ȥ��ȴ����������ȥ��ʱ������

ԼԼ���ƺ���Щʲô�������������䶯��

LONG

	);



	set("valid_startroom",1);



	setup();

}



void init()

{

	object ob = this_player();



	if( (int)ob->query_condition("be_caught") <= 0 )

	{

		message("vision",

			HIR "ֻ����ͨһ����һ���������˵ļһﱻ���˽�����\n\n" NOR, 

			environment(ob), ob);



		ob->set("startroom", "/d/xingxiu/laofang");

		ob->apply_condition("be_caught", 30);

	}

}