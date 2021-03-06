// Room: /d/wuguan/npc/tiatian.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("寻花", ({ "xun hua","xun"}) );
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
		command("say 您好吗？欢迎！现在由我来教你一些简单的交谈技巧。\n");
       	        command("tell " + ob->query("id") + " HI!WELCOME!");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 首先，要知道现在有什么玩家在线，可以用who命令查查。\n");	
	command("say 只要输入who命令，就可以查询现在在线玩家的中文名字。\n");			
	command("say 只要输入who -i命令，就可以查询现在在线玩家的英文名字。\n");	
	command("say 只要输入who -l命令，就可以查询现在在线玩家的中英文名字。\n");
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 你现在可以随便找一个在线玩家的英文名字。用tell与他单独交谈。\n");	
	command("say 方法是：tell <玩家英文名> [交谈内容]。\n");	
	command("say 如果该名玩家回答你的话，之后的谈话就可以用reply 命令。\n");							
	command("say 方法是：reply [回答内容]。\n");					
	command("say reply  命令是用于回答用的，方便于不用每次都要输入对方的名字。\n");							
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 以上是两个玩家单独交谈的方法。好处是其他人没法看见。\n");	
	command("say 还有say命令与chat命令。\n");	
	command("say say命令是让同一场景的所有人都听见你说话，方法是：say [内容]。\n");							
	command("say 方法是：reply [回答内容]。\n");					
	command("say chat命令是让整个游戏中的玩家都能听见你的说话，方法与say类似。\n");							
	call_out("teach4",7,ob);
}	




void teach4(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say who,tell,say,reply 命令都可以用help来查询，方法是：help <命令名>。\n");	
	command("say 如果你基本了解，可以试一下，然后请往东(east)走。\n");	
}	
