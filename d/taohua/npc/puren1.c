// puren1.c



#include <ansi.h>

inherit NPC;





void greeting(object);

void init();

void create()

{

	set_name("����", ({ "pu ren","ren","pu" }) );

	set("gender", "����" );

	set("age", 30);

	set("long", "һ�������Ц������,��Ц�����������㡣\n");

	set("combat_exp", 5000);

	set("str", 17);

	set("dex", 16);

	set("con", 18);

	set("int", 20);

	set("attitude", "peacely");

	set("max_qi", 150);

	set("max_jing", 150);



	set_skill("force", 15);

	set_skill("dodge", 15);

	set_skill("unarmed", 15);

	set_skill("parry", 15);



	setup();

	carry_object("/d/taohua/obj/cloth")->wear();

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

{

	if( !ob || environment(ob) != environment() ) return;

	if((string)ob->query("family/family_name")=="�һ���")

	   { say(WHT "����Ц������˵������λ" + RANK_D->query_respect(ob)

	     + "�������ˣ�������ɡ���\n" NOR);

	     return;

	    }

	if(!ob->query("family/family_name"))

	   { say(WHT "��������Ц�ݵ�˵������λ" + RANK_D->query_respect(ob)

	     + ",��ӭ��������ׯ���͡�\n������Ҫ����Ŷ��\n" NOR);

	     return;

	    }



}



