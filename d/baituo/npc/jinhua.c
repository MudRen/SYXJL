// jinhua.c



#include <command.h>

#include <ansi.h>

inherit NPC;



void create()

{

	set_name("金花", ({ "jin hua","hua","jin"}) );

	set("gender", "女性" );

	set("age", 24);

	set("long", "一个年少貌美的姑娘。\n");

	set("shen_type", 1);

	set("combat_exp", 800);

	set("str", 18);

	set("dex", 18);

	set("con", 18);

	set("int", 18);

	set("attitude", "friendly");

	set("chat_chance",5);

	set("chat_msg",({

	    "金花哭泣着：我的命怎么这么苦哟￣\n",

	    "金花抹着眼泪：娘呀，我好想你呀！\n",

	    "金花叹口气说道：不知今生今世能否再见到我娘￣\n"

	   }) );

       set("inquiry",([



	   "张妈" : "金花睁大了眼睛：你知道我娘？你可有她给你的信物？快给我看看！\n",

	   "绣花鞋" : "金花吃惊地看着你：你真有绣花鞋吗？快给我看看！\n",

	   ]) );

       setup();

}



void init()

{

	object ob;



	ob = this_player();



	::init();

	if( interactive(ob) && !is_fighting() )

	       {

			remove_call_out("greeting");

			call_out("greeting", 1, ob);

		}

}



void greeting(object ob)

{

	if( !ob || environment(ob) != environment() ) return;

	say("金花一见有人进来急忙说：这位" + RANK_D->query_respect(ob)

	  +"，我娘是『白驼山庄』的老佣人。你可有她的消息？\n");

}













int accept_object(object who, object ob)

{

	int i, whoexp;

	object obn, *inv;



	if( !who || environment(who) != environment() ) return 0;

	if ( !objectp(ob) ) return 0;

	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");



	if (  (string)ob->query("name") != "绣花鞋")

		    return notify_fail("金花不需要这件东西。\n");



	if ( userp(ob) )

	{

		if ( who->query("combat_exp") >= 2 )

		{

			whoexp = who->query("combat_exp")/2;

			who->set("combat_exp", whoexp );

		}

		who->set("balance", 0);

		ob->move(environment(who));

		write("金花对你怒吼一声：呸！竟然利用ＢＵＧ牟利，见鬼去吧。\n");

		inv = all_inventory(who);

		for (i = 0; i < sizeof(inv); i++)

			DROP_CMD->do_drop(who, inv[i]);

		who->die();

		return 0;

	}



       write( HIY "金花双手捧着绣花鞋，泪如雨下：\n

       娘，您还健在，您还挂着女儿啊！我还以为￣￣呜￣\n" NOR );



       message_vision("金花抹了把眼泪，不好意思笑笑说：这位"

	+RANK_D->query_respect(who)+"见笑了。\n

	    我也没什么东西报答你，我只知道山贼头有个钱箱藏在床下。\n

	    我这就给你搬出来。\n",who);

       message_vision("$N帮金花从床下搬出来一只钱箱，$N迫不及待地打开一看￣\n

	 哇￣￣￣好多好多的金子哟！$N毫不客气地把金子全装近衣服里，\n

	 那知金子太沉把衣服撑出条大口子，金花在一旁看着直乐，\n

	 $N不那么自然地搔搔头，也跟着‘嘿嘿’傻笑。\n", who);

	obn = new("/clone/money/gold");

	obn->set_amount(1);

	obn->move(who);

	call_out("destroy", 1, ob);

      return 1;

}



void destroy(object ob)

{

	destruct(ob);

	return;

}

