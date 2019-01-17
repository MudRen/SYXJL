// gargoyle.c



#include <ansi.h>

#include <command.h>

#include <login.h>



inherit NPC;



string *death_msg = ({

	HIB "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,

	HIB "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,

	HIB "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,

	HIB "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,

	HIB "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"

		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,

});



void create()

{

	set_name("���޳�", ({ "black gargoyle", "gargoyle" }) );

	set("long",

		"���޳�������������ͷ�����㣬��ڵ����Ͽ������κ�ϲŭ���֡�\n");

	set("attitude", "peaceful");

	set("chat_chance", 15);

	set("chat_msg", ({

		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",

		"���޳��ѳ�������ͷ��������������������Լ��ֺ��ֳ�����ָ��\n"

	}) );

	set("age", 217);

	set("combat_exp", 5000000);

	set("max_jing", 1000);

	set("max_qi", 1000);

	set_skill("dodge", 300);

	set_skill("parry", 300);

	set_skill("unarmed", 300);

	set_temp("apply/armor", 300);

	set_temp("apply/damage", 300);

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

	message_vision(HIB"���޳�����$N���һ�����ô�Ĺ�����Ȼ�ڵظ��ڴ򶷣�\n"NOR, me);

	kill_ob(me);

	me->fight_ob(this_object());

	return 0;

}



/*
void death_stage(object ob, int stage)

{

	int i;

	object *inv;



	if( !ob || !present(ob) ) return;



	if( !ob->is_ghost() && !wizardp(ob) ) {

		command("say ι��������������ʲô��");

		kill_ob(ob);

		ob->fight_ob(this_object());

		return;

	}



	tell_object(ob, death_msg[stage]);

	if( ++stage < sizeof(death_msg) ) {

		call_out( "death_stage", 5, ob, stage );

		return;

	} else

		ob->reincarnate();



	inv = all_inventory(ob);

	for (i = 0; i < sizeof(inv); i++)

		DROP_CMD->do_drop(ob, inv[i]);



	ob->move(REVIVE_ROOM);

	message("vision",

		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"

		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);

}

*/
