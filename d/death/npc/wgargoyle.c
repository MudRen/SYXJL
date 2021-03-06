// gargoyle.c



#include <ansi.h>

#include <command.h>

#include <login.h>



inherit NPC;


int dan_ask();

string *death_msg = ({

	HIW "白无常说道：喂！新来的，你叫什么名字？\n\n" NOR,

	HIW "白无常用奇异的眼光盯著你，好像要看穿你的一切似的。\n\n" NOR,

	HIW "白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,

	HIW "白无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,

	HIW "白无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"

		"一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,

});



void create()

{

	set_name("白无常", ({ "white gargoyle", "gargoyle" }) );

	set("long",

		"白无常伸著长长的舌头瞪著你，死白的脸上看不出任何喜怒哀乐。\n");

	set("attitude", "peaceful");

	set("chat_chance", 15);

	set("chat_msg", ({

		"白无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",

		"白无常把长长的舌头伸出来，缓缓地舔了舔自己又白又长的手指。\n"

	}) );

	set("age", 217);

	set("combat_exp", 1000000);

	set("max_jing", 1000);

	set("max_qi", 1000);

	set_skill("dodge", 100);

	set_skill("parry", 100);

	set_skill("unarmed", 100);

	set_temp("apply/armor", 100);

	set_temp("apply/damage", 100);

  set("inquiry", ([
        "天王保命丹" : (: dan_ask() :),
  ]));
	setup();

}



void init()

{

	::init();

	add_action("do_fight","fight");

	add_action("do_fight","hit");

	add_action("do_fight","kill");

	if( !previous_object()

	||	!userp(previous_object())

	||	wizardp(previous_object()) ) return;

	call_out( "death_stage", 5, previous_object(), 0 );

}



int do_fight(string arg)

{

	object me;

	me = this_player();

	message_vision(HIW"白无常对着$N大喝一声：好大的鬼胆，竟然在地府内打斗！\n"NOR, me);

	kill_ob(me);

	me->fight_ob(this_object());

	return 1;

}



void death_stage(object ob, int stage)

{

	int i;

	object *inv;

	if( !ob || !present(ob) ) return;



	tell_object(ob, death_msg[stage]);

	if( ++stage < sizeof(death_msg) ) {

		call_out( "death_stage", 5, ob, stage );

		return;

	} else

		ob->reincarnate();



	inv =  all_inventory(ob);

	for (i = 0; i < sizeof(inv); i++)

		DROP_CMD->do_drop(ob, inv[i]);

	ob->move(REVIVE_ROOM);
        ob->set("food", (ob->query("str")+10)*10);
        ob->set("water", (ob->query("str")+10)*10);


	message("vision",

		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"

		"很久了，只是你一直没发觉。\n", environment(ob), ob);

}

int dan_ask ()
{
  object who = this_player();
  object me = this_object();
  object dan = 0;

  command ("nod");
  dan = new ("/clone/medicine/dan.c");
  dan->move(me);
  command ("whisper "+who->query("id")+" 好自为之！");
  command ("give "+who->query("id")+" dan");
  who->save();
  return 1;
}
