// foreman.c

inherit NPC;

//void relay_say();

void new_crate();

void create()

{

	set_name("工头", ({ "foreman" }) );

	set("age", 48);

	set("long",

"这位就是这家货栈的工头，负责指挥工人将货物搬进搬出，如果\n"

"你想打工赚些钱，可以跟他谈谈看　\n");

//	set("inquiry", ([

//		"工作" : (: relay_say() :),

//	]));



	set("chat_chance", 10);

	set("chat_msg", ({

		(: new_crate :),

		"工头大声吆喝著工人将货物从仓库搬出来　\n",

		"工头大叫：小王呢？今天有没有来？\n",

		"工头说道：谁再去多找些人手，唉，忙死了　\n",

		"工头说道：要算工钱的一个个来 ... 别急 ...\n"

	}) );



	setup();

	add_money("silver",2);

}



void relay_say(object me, string msg)

{

	object money;

	if( me->is_fighting() || me->is_chatting() ) return;

	if( strsrch(msg, "工钱") >= 0 ) {

	int amount;

  	add_money("silver",2);

		if( amount = me->query_temp("wage_deserved") ) {

		money = new("/obj/money/coin");

		money->set_amount(amount);

		money->move(this_object());

		command("say 好，好 ... 总共是" + chinese_number(amount) + "文钱，哪，给你　");

		me->delete_temp("wage_deserved");

		command("give coin to " + me->query("id"));

		}

	else say("工头说道：搬一个箱子五文钱，损坏的赔三倍　\n");

	return;

	}

}



void new_crate()

{

	object ob;

	if( !environment()

	||sizeof(all_inventory(environment())) >= 15 ) return;

	ob = new(__DIR__"obj/crate");

	ob->move(environment());

	say("工头说道：喂！那边卸货的小心一点，别给摔坏了！\n");

}

