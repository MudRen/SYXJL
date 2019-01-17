//yan.c
inherit NPC;
void greeting(object);
void init();
void create()
{
       set_name("柳如烟", ({ "liuru yan","liu" }) );
	set("gender", "女性" );
	set("age", 20);
	set("long", "她就是桃花岛的厨师。是个容貌姣好的女子， 瓜子脸蛋，\n"
	    "眼如点漆， 清秀绝俗。\n");
	set("combat_exp", 10000);
	set("str", 20);
	set("dex", 22);
	set("con", 20);
	set("per", 24);
	set("attitude", "friendly");
	setup();
	carry_object("/d/city/npc/obj/pink_cloth")->wear();
	add_money("silver",50);
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
	object obn;
	if( !ob || environment(ob) != environment() ) return;
	if(((string)ob->query("family/family_name")=="桃花岛")&&(random(3)==1))
	{
		say("柳如烟笑吟吟地说道：这位" + RANK_D->query_respect(ob)
		+ "您饿了吧，请用餐。\n");
		obn=new("/d/taohua/obj/gao");
		obn->move(environment(ob));
		obn=new("/d/taohua/obj/cha");
		obn->move(environment(ob));
	}
	else 
	say("柳如烟微微一笑，说道：这位" + RANK_D->query_respect(ob)
		+ "，欢迎来参观，可不要偷吃哟。\n");
	return;
}