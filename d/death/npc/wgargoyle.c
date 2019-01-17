// gargoyle.c



#include <ansi.h>

#include <command.h>

#include <login.h>



inherit NPC;


int dan_ask();

string *death_msg = ({

	HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,

	HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,

	HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,

	HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,

	HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"

		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,

});



void create()

{

	set_name("���޳�", ({ "white gargoyle", "gargoyle" }) );

	set("long",

		"���޳�������������ͷ�����㣬���׵����Ͽ������κ�ϲŭ���֡�\n");

	set("attitude", "peaceful");

	set("chat_chance", 15);

	set("chat_msg", ({

		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",

		"���޳��ѳ�������ͷ��������������������Լ��ְ��ֳ�����ָ��\n"

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
        "����������" : (: dan_ask() :),
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

	message_vision(HIW"���޳�����$N���һ�����ô�Ĺ�����Ȼ�ڵظ��ڴ򶷣�\n"NOR, me);

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

		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"

		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);

}

int dan_ask ()
{
  object who = this_player();
  object me = this_object();
  object dan = 0;

  command ("nod");
  dan = new ("/clone/medicine/dan.c");
  dan->move(me);
  command ("whisper "+who->query("id")+" ����Ϊ֮��");
  command ("give "+who->query("id")+" dan");
  who->save();
  return 1;
}
