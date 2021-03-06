// Room: /d/wuguan/npc/orange.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("桔子", ({ "ju zi","orange"}) );
	set("gender", "男性" );
	set("age", 22);
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
		command("say 您好！！我是负责教新人一些基本冒险指令的，多多指教。\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 首先，向您讲解一下ask指令，ask是用于问NPC问题的一个命令。\n");	
	command("say 在游戏中，有很多NPC可以用ask问其一些重要信息。\n");			
	command("say 方法是：ask <NPC英文名字> about [内容]。\n");	
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 现在跟你说一说关于look，i指令。\n");	
	command("say look即是看的意思。方法是：look [(他人或物品)]，可简写为l。\n");	
	command("say 你可以输入l看一看自己身在场景的描述，也可以l ju zi 看看我。\n");							
	command("say 如果你输入i，就能看见自己身上的东西（新人刚来通常只有一件衣服）。\n");					
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 然后我们说一说get，drop，give指令。\n");	
	command("say get 是捡起某样物品，drop是扔掉某样物品，give是给别人东西。\n");	
	call_out("teach4",5,ob);
}	




void teach4(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 现在要讲解buy，sell，open，close等常用的指令。\n");	
	command("say buy能够在店铺与当铺买东西，sell能够在当铺卖掉自己的东西。\n");
	command("say open与close分别是打开与关闭门或窗。\n");
	call_out("teach5",7,ob);
}



void teach5(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 最后说一说的是wear，remove和sleep命令。\n");	
	command("say wear与remove分别是穿戴与脱掉衣服饰物用的，sleep是睡觉命令。\n");
	command("say 丐帮弟子可以随地睡觉，其他门派的要找休息室之类的场景才能睡觉。\n");
	command("say 想知道详细一点的话，可以用help查询以及自己实践。\n");	
}		
