//feifei.c

#include <command.h>

inherit NPC;

void greeting(object);

void init();

void create()

{

       set_name("肥肥", ({ "fei fei","fei" }) );

	set("gender", "男性" );

	set("age", 35);

	set("long", "一个肥头大耳的厨师，两只小眼睛不停地眨巴着。\n");

	set("shen_type", -1);

	set("combat_exp", 10000);

	set("str", 20);

	set("dex", 22);

	set("con", 20);

	set("int", 21);

	set("attitude", "friendly");

	setup();

	carry_object("/clone/misc/cloth")->wear();

	 add_money("silver",50);

}

void init()

{

	object ob;



	::init();



	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");

		call_out("greeting", 1, ob);

	}

}

void greeting(object ob)

{  object obn;

	if( !ob || environment(ob) != environment() ) return;

	if(((string)ob->query("family/family_name")=="白驼山派")&&(random(3)==1))

	{say("肥肥笑吟吟地说道：这位" + RANK_D->query_respect(ob)

	     + "您饿了吧，请用餐。\n");

	     obn=new("/d/baituo/obj/cake");

	      obn->move(environment(ob));

	     obn=new("/d/baituo/obj/doujiang");

	      obn->move(environment(ob));

	   }

	else 

	     say("肥肥小眼一眨，笑吟吟地说道：这位" + RANK_D->query_respect(ob)

	     + "，欢迎来参观，可不要偷吃哟。\n");

	   return;

}

int accept_object(object who, object ob)

{

	int i, whoexp;

	object obn, *inv;



	if( !who || environment(who) != environment() ) return 0;

	if ( !objectp(ob) ) return 0;

	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if (  (string)ob->query("name") != "柴"  )

	   return notify_fail("肥肥不要这件东西。\n");



	if ( userp(ob) )

	{

		if ( who->query("combat_exp") >= 2 )

		{

			whoexp = who->query("combat_exp")/2;

			who->set("combat_exp", whoexp );

		}

		who->set("balance", 0);

		ob->move(environment(who));

		write("肥肥对你怒吼一声：呸！竟然利用ＢＵＧ牟利，见鬼去吧。\n");

		inv = all_inventory(who);

		for (i = 0; i < sizeof(inv); i++)

			DROP_CMD->do_drop(who, inv[i]);

		who->die();

		return 0;

	}



	command("smile "+(string)who->query("id"));

	if (random(3)==1)

	{

		obn = new("/clone/money/silver");

		obn->set_amount(12);

		obn->move(who);

		tell_object(who,"我多给你二两银子，不要声张！\n");

	}

	else

	{

		obn = new("/clone/money/silver");

		obn->set_amount(10);

		obn->move(who);

	tell_object(who,"再接再励，以后我会给你好处的！\n");

	}

	call_out("destroy", 1, ob);

	return 1;

}



void destroy(object ob)

{

	destruct(ob);

	return;

}



