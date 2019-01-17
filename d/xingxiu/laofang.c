// laofang.c

// by QingP



#include <ansi.h>



inherit ROOM;



void create()

{

	set("short", "牢房");

	set("long", @LONG

这是一个阴暗潮湿的山洞，空气中散发着一阵阵令人作呕的

腐臭气味。黑暗的角落里蜷缩着几个人影，对你的出现似乎毫无

知觉。地上躺着一个人，仔细看去，却发现早已死去多时，隐隐

约约的似乎有些什么东西在他身上蠕动。

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

			HIR "只听扑通一声，一个遍体鳞伤的家伙被扔了进来！\n\n" NOR, 

			environment(ob), ob);



		ob->set("startroom", "/d/xingxiu/laofang");

		ob->apply_condition("be_caught", 30);

	}

}