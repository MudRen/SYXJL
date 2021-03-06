// Room: /d/wuguan/npc/lxq.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("浪翻云", ({ "lang fanyun","lang","lxq"}) );
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
		command("say 接着是说一说nick与describe命令。\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say nick是用来描写你自己的绰号的，而describe是用来写自己的描述。\n");	
	command("say nick与describe并不一样，nick是绰号，是放在你名字前面的。\n");			
	command("say 而用describe写的描述是要别人look才能看见的。\n");	
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 然后是两个很重要的命令：save与quit。\n");	
	command("say save即是存档，由于系统会定时自动存档，所以一般情况下请别常用。\n");	
	command("say quit是退出游戏，退出游戏的时候身上有些物品会丢下的，请留意一下。\n");							
}

