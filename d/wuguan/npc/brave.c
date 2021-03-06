// Room: /d/wuguan/npc/brave.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("勇敢的心", ({ "yonggan dexin","yonggan","brave"}) );
	set("gender", "男性" );
	set("age", 27);
	set("long",
		"神秘人物。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("mud_age")<1000)	
	{
		command("hi " + ob->query("id"));
		command("say 本游戏有一片很大的地域，所以你要清楚如何走四方。\n");
		call_out("teach1",3,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 你每到一处场景的时候，都会看到类似“这里的出口是 north 和 west。”。\n");	
	command("say 这代表了能往西与北走。你可以输入north或n往北走，因为n是north的简化。\n");			
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 以下是各方向的简化：\n");	
	command("say north==n；south==s；west==w；east==e；\n");	
	command("say northwest==nw；        northeast==ne；\n");							
	command("say southwest==sw；        southeast==se；\n");					
	command("say southup==su；northup==nu；eastup==eu；westup==wu；\n");				
	command("say southdown==sd；        northdown==nd；\n");					
	command("say westdown==wd；         eastdown==ed。\n");										
	command("say 还有一些特殊的出口，在此不作介绍。\n");										
	command("whisper " + ob->query("id") + " 请往西南(southwest)走，那边有专人教你如何与他人谈话的。\n");												
}

