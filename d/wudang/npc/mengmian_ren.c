// mengmian_ren.c

// creat by honest



#include <ansi.h>



inherit NPC;

void do_kills();

void do_killing();

int skill=random(400)+50;

int i;

object *ob;

object me=this_object();



void create()

{

	set_name(RED"������"NOR, ({ "mengmian ren", "ren","mengmian"}));

	set("long", 

		"���Ǹ��ú���ɴ��ס��׵��ˡ�\n");

	set("title", HIW"���׼���"NOR);

	set("gender", "����");

	set("age", random(20)+20) ;

	set("pursuer", 1);



	set("str", 30);

	set("int", 20);

	set("con", 30);

	set("dex", 30);

        

	set("max_qi", 1000);

	set("max_jing", 400);

	set("neili", 1000);

	set("max_neili", 1000);

	set("combat_exp", skill*1000);

	set("shen_type", -1);



	set_skill("force", skill);

	set_skill("dodge", skill);

	set_skill("unarmed", skill);

	set_skill("parry", skill);

	set_skill("sword", skill);



	setup();

	carry_object("/clone/weapon/changjian")->wield();

}



void init()

{

        ::init();
	if (present("zhike daozhang", environment(me)) &&

		living(present("zhike daozhang", environment(me)))) {

	remove_call_out("do_kills");

	call_out("do_kills",0);

	}

	if (interactive(this_player())&&!is_fighting()) {

	remove_call_out("do_killing"); 

	call_out("do_killing",1);

	}

}



void do_kills()

{

	say(HIY"������һ�Բ������ٽ������֪�͵�����\n"NOR);

	say(HIW"֪�͵������һ�������󵨿�ͽ�����ҵ��䵱ɽ����Ұ����\n"NOR);

	me->kill_ob(find_living("zhike daozhang"));

	find_living("zhike daozhang")->kill_ob(me);

	return;

}



void do_killing()

{

	ob = all_inventory(environment(me));

        if (environment(me)->query("no_fight")) return;

	for(i=sizeof(ob)-1; i>=0; i--) {

	if (living(ob[i]) && random(10)>4 && ob[i] != me) {

		me->set_leader(ob[i]);

		me->kill_ob(ob[i]);

		ob[i]->fight(me);

	}

	else continue;

	}

	return;

}

