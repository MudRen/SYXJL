

#include <ansi.h>



inherit NPC;



int do_eat();

int do_drink();

int do_say();

int do_tell();

int do_chat();

int do_emote();

int do_dazuo();

int do_tuna();

int do_study();

int do_lian();

int do_yun();

int do_cha();

int do_learn();

int do_teach();

int do_perform();

int do_vote();



void create()

{

	set_name("万无天", ({ "wan wutian", "wan", "wutian" }));

	set("title", HIC "最酷的看守" NOR);

	set("nickname", HIY "胡思乱想" NOR);

	set("gender", "男性");

	set("age", 24);

	set("long", "没什么可看的，一个普通人罢了。\n");

	set("shen_type", 1);

	set("attitude", "peaceful");

	set("chat_chance", 5);

	set("chat_msg", ({

		"万无天自言自语说：“想出去么？找tender问问好了。”\n",

		"万无天呵呵笑了笑，说：“被关在这里都是原因的，不是么？”。\n",

	}) );

	setup();

	carry_object("d/city/obj/cloth")->wear();

}



void init()

{

	object ob = this_player();

	::init();

	ob->set("startroom", "/u/tender/workroom");



	if(wizardp(ob)) return;

	add_action("do_eat", "eat");

	add_action("do_drink", "drink");

	add_action("do_say", "say");

	add_action("do_tell", "tell");

	add_action("do_tell", "reply");

	add_action("do_tell", "ce");

	add_action("do_chat", "chat");

	add_action("do_chat", "rumor");

	add_action("do_chat", "music");

	add_action("do_emote", "emote");

	add_action("do_emote", "chat*");

	add_action("do_emote", "rumor*");

	add_action("do_emote", "music*");

	add_action("do_dazuo", "dazuo");

	add_action("do_dazuo", "exercise");

	add_action("do_tuna", "tuna");

	add_action("do_tuna", "respirate");

	add_action("do_study", "study");

	add_action("do_study", "du");

	add_action("do_lian", "lian");

	add_action("do_lian", "practice");

	add_action("do_yun", "exert");

	add_action("do_yun", "yun");

	add_action("do_yun", "nixing");

	add_action("do_cha", "cha");

	add_action("do_cha", "check");

	add_action("do_learn", "learn");

	add_action("do_learn", "xue");

	add_action("do_teach", "teach");

	add_action("do_teach", "jiao");

	add_action("do_perform", "perform");

	add_action("do_vote", "vote");

}



int do_eat()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N看了看$n，说：“呵呵，这里不准随便吃零食。”\n", me, ob );



	return 1;

}



int do_drink()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n一笑，说：“呵呵，这里禁止酗酒。”\n", me, ob );



	return 1;

}



int do_say()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n叹了口气道：“什么也不用说了，好好反省吧。”\n", me, ob );



	return 1;

}



int do_tell()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n嘿嘿一乐，说：“想给同伙通风报信啊？”\n", me, ob );



	return 1;

}



int do_chat()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n摇了摇头，说：“你再怎么喊也是没有用的了。”\n", me, ob );



	return 1;

}



int do_emote()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N看着$n笑了：“呵呵，等你出去后再表情丰富吧。”\n", me, ob );



	return 1;

}



int do_dazuo()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n一乐道：“呵呵，您还是省点体力吧。”\n", me, ob );



	return 1;

}



int do_tuna()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n眨了眨眼：“呵呵，您还是省点精力吧。”\n", me, ob );



	return 1;

}



int do_study()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N冲$n摇了摇头，说：“你要学的东西不在书上。”\n", me, ob );



	return 1;

}



int do_lian()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n叹了口气道：“身体要紧，你还是休息休息吧。”\n", me, ob );



	return 1;

}



int do_yun()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对着$n哈哈大笑道：“您内功卓越我早已知道了。”\n", me, ob );



	return 1;

}



int do_cha()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n哼了一声，说：“不老实悔过查别人做什么？”\n", me, ob );



	return 1;

}



int do_learn()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N拍了拍$n，说：“好学值得表彰，不过现在不成。”\n", me, ob );



	return 1;

}



int do_teach()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n笑了笑，说：“想教别人也学坏啊？”\n", me, ob );



	return 1;

}



int do_perform()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N看着$n笑了：“呵呵，武艺不错这我也知道了。”\n", me, ob );



	return 1;

}



int do_vote()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N对$n笑了笑，说：“现在这样您还不忘民主啊？”\n", me, ob );



	return 1;

}

