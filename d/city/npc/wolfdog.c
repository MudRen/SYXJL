// wolfdog.c

#include <login.h>
#include <move.h>
inherit NPC;

void create()
{
	set_name("大狼狗", ({ "wolf dog", "dog" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的大狼狗。像是财主家里养的宠物。\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);

	set("chat_chance", 6);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"大狼狗大声吠叫：汪！汪！汪！汪！汪！汪！\n",
		"大狼狗突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
	}) );

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
	}
	add_action("do_throw", "wei");
}

int do_throw(string arg)
{
	object obj, me, corpse, *inv;
	string arg1, arg2;

	me = this_player();
	inv = all_inventory(me);

	if ( !arg || arg=="" )
		return notify_fail("什么？\n");

	if ( sscanf(arg, "%s to %s", arg1, arg2) !=2 )
		return notify_fail("什么？\n");

	if ( !inv )
		return notify_fail("你身上什么东西都没有，扔什么呀？\n");

	obj = present(arg1, me);
	if ( !obj ) return notify_fail("什么？\n");
	if ( !obj->is_character() || obj->is_corpse() )
		return notify_fail("这个东西大狼狗是不会吃的。\n");

	if ( arg2 == "dog" || arg2 == "wolf dog" )
	{
		message_vision("$N把$n朝大狼狗扔了过去。大狼狗立刻扑了上来一口咬住$n的脖子。\n", me, obj);
		message_vision("$N无力的挣扎了几下，大狼狗越咬越紧，$N眼看就不行了。\n", obj);
		if ( userp(obj) ) {
		obj->clear_condition();
		COMBAT_D->announce(obj, "dead");
		if ( objectp(corpse = CHAR_D->make_corpse(obj, this_object())) )
			corpse->move(environment(this_object()));
		corpse->move(environment());
		obj->remove_all_killer();
		all_inventory(environment())->remove_killer(obj);
		obj->dismiss_team();
		obj->set("jing", 1);
		obj->set("eff_jing", 1);
		obj->set("qi", 1);
		obj->set("eff_qi", 1);
		obj->set_ghost(1);
		obj->revive(1);
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("%s被某人喂了大狼狗。", obj->name(1)));
		COMBAT_D->killer_reward(this_object(), obj);
		obj->move(DEATH_ROOM);
		DEATH_ROOM->start_death(obj);
		} else
		obj->die();
		return 1;
	}
	return 0;
}

void die()
{
	object ob;
	message_vision("$N惨嚎一声，死了！\n", this_object());
	ob = new(__DIR__"obj/goupi");
	ob->move(environment(this_object()));
	destruct(this_object());
}

