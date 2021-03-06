#include <ansi.h>

inherit NPC;

//string keep_msg = 0;
object follow_ob = 0;
int password_try = 0;

void create()
{
        set_name("鹦鹉", ({ "parrot", "yingwu" }) );
        set("race", "野兽");
        set("gender", "雄性" );
        set("age", 2);
        set("long", "一只会说话的小绿鹦鹉。\n");
	set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "翅膀", "尾部" }) );
        set("verbs", ({ "claw", "poke" }) );

        set("str", 15);
        set("dex", 100);
        set("con", 15);
        set("int", 20);

        set("combat_exp", 800);

	set_skill("dodge", 500);

	set_temp("apply/attack", 6);
        set_temp("apply/defense", 6);
        set_temp("apply/dexerity", 100);
        set_temp("apply/armor", 3);

        set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: force_me, "!!!" :),
	}));
	set("chat_chance", 5);
	set("chat_msg", ({
		(: force_me, "chicken" :),
	}));

        setup();
        set("race", "飞禽");
	set("can_speak", 1);
}

void init()
{
	object ob = this_player();

/*	if (ob->id("parrot") && !userp(ob)) {
                set("disable_type", " ");
                call_out("self_destruct", 1, ob);
        }
	add_action("do_say", "say");
*/
	::init();
	if ((!follow_ob || !objectp(follow_ob) || !random(10)) && userp(ob)) {
		command("follow " + ob->query("id"));
		follow_ob = ob;
	}
	if (objectp(follow_ob) && !present(follow_ob, environment(this_object())))
                call_out("continue_follow", 1, follow_ob);
}

int continue_follow(object ob)
{
	if (objectp(ob) && !present(ob, environment(this_object()))) {
		say("鹦鹉忽然振翅飞走了。\n");
		move(environment(ob));
		message_vision("鹦鹉飞了过来，停在$N的肩膀上。\n", ob);
	}
}


/*
int self_destruct(object ob)
{
	delete("disable_type");
	if (ob && present(ob, environment(this_object()))) {
		say("两只鹦鹉一见面就互相啄了起来，一只被咬得飞走了。\n");
		destruct(this_object());
	}
}

int do_say(string arg)
{
	int i;

	if (keep_msg) {
		remove_call_out("repeat_msg");
		say(CYN + "鹦鹉重复道：" + keep_msg + NOR);
		keep_msg = 0;
	}
	return 0;
}

void repeat_msg()
{
	say(CYN + "鹦鹉重复道：" + keep_msg + NOR);
	keep_msg = 0;
}

void relay_message(string msgclass, string msg)
{
	int i;

	if (keep_msg) {
		remove_call_out("repeat_msg");
		say(CYN + "鹦鹉重复道：" + keep_msg + NOR);
		keep_msg = 0;
	}
	if (!msg) return;
	if (msgclass == "sound") {
		i = strsrch(msg, "说道：") + 6;
		keep_msg = msg[i..];
		call_out("repeat_msg", 1);
	}
}
*/

void relay_say(object ob, string msg)
{
	int i;

	if (!msg) return;
	say(CYN + "鹦鹉重复道：" + msg + "\n" + NOR);
}


int return_home(object home)
{
        // At home already?
        if (!environment() || environment()==home)
                return 1;

        // Able to leave?
        if (!living(this_object()) || is_fighting()) return 0;

	if (!follow_ob || !objectp(follow_ob)) {
	        message("vision", this_object()->name() + "急急忙忙地飞走了。\n",
        	        environment(), this_object());
	        if (move(home)) {
        	        message("vision", this_object()->name() + "急急忙忙地飞了过来。\n",
                	        environment(), this_object());
			return 1;
        	}
		return 0;
	}
	return 1;
}


void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N正想对鹦鹉下毒手，忽然被人踢了个跟头，一个动物保护主义者喝道：“请爱护小动物！”\n", ob);
}

int accept_fight(object ob)
{
	message_vision("鹦鹉对着$N大叫：“" + RANK_D->query_rude(ob) + "，有本事杀我呀！”\n", ob);
	return 0;
}

