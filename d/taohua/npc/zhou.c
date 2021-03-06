// zhou.c 周伯通 
//Ronger 10/98
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_jiebai();
int do_back(object me);
void create()
{
	set_name("周伯通",({ "zhou botong","zhou","botong" }) );
	set("nickname",HIY"老顽童"NOR);
	set("gender", "男性" );
	set("age", 83);
	set("long", 
		"他就是人称老顽童的周伯通，虽然满头白发，可是仍然象个孩子，\n"+
		"成天笑嘻嘻的，一双眼睛盯着你不停地骨碌碌乱转。\n");
	set("inquiry", ([
		"郭靖" : "他可是我的好兄弟，只是很久没见他了。\n",
		"结拜" : (: do_jiebai :),
	]));

	set("str", 30);
	set("dex", 30);
	set("con", 25);
	set("int", 20);
	set("combat_exp", 1800000);
	set("attitude", "friendly");
	set("score", 400000);
	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 8500);
	set("max_neili", 8500);
	set("jiali", 100);

	set_skill("force", 200);
	set_skill("xiantian-gong", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("quanzhen-shenfa", 200);
	set_skill("parry", 200);
	set_skill("kongming-quan",200);
	set_skill("hubo", 300);
	set_skill("sword",200);
	map_skill("unarmed", "kongming-quan");
	map_skill("parry", "kongming-quan");
	map_skill("force", "xiantian-gong");
	map_skill("dodge", "quanzhen-shenfa");

	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
		(: command("say 你我无冤无仇，何必如此?\n") :),
		(: command("sigh") :),
		(: command("hubo") :),
		(: command("sigh") :),
		(: command("hubo") :),
		(: command("yun regenerate") :),
		(: command("hubo") :),
		(: command("yun recover") :),
		(: command("hubo") :),
		}) );

          create_family("全真教", 3, "弟子");
	setup();
	carry_object("d/taohua/obj/cloth")->wear();
}
int do_jiebai()
{
	object ob;
	ob=this_player();
	if(ob->query("gender")!="男性")
	{
		say("周伯通说道：“我老顽童生平最讨厌女人，去！去！去！别来烦我。”\n");
		return 1;
	}
	if((string)ob->query("zhou/canlearn") =="1")
	{
		say("周伯通说道：“咱们不是已经结拜了吗？”\n");
		return 1;
	}
              if(ob->query("int")> 25)
	{
	say("周伯通说道：“看你一副鬼机灵的样子，和我兄弟郭靖的老婆一样。”\n"
	    "周伯通摇了摇头，说道：“你回去吧。”\n");
	return 1;
	}
	else
	say("周伯通高兴的拉着"+ob->query("name")+"的手说道：“我们以后就是好兄弟。”\n");
	command("tell "+ob->query("id")+" 哥哥我有一套空明拳和一套双手互搏的功夫，可以教你。\n"); 
	this_player()->set("zhou/canlearn", "1");
	return 1;
}
int recognize_apprentice(object ob)
{
	if ((string)ob->query("zhou/canlearn") != "1")
	{
		message_vision("$N摇了摇头。\n",this_object());
//		command("tell "+ob->query("id")+" 我为什么要教你功夫呢？\n"); 
		return 0;
	}

	return 1;
}
int accept_object(object who, object ob)
{
	object me;
	me=this_object();
	if((string)ob->query("name") == "毒蛇")
        {
        call_out("destrory",1,me);
        message_vision("$N掏出一条毒蛇，在周伯通眼前晃了晃，周伯通吓得连忙往洞外跑，一边跑一边\n"
	"叫着：“哇，蛇！蛇！咬死我啦！”只听声音越来越远，越来越小，终不可闻。\n",who);        
	return 1;
        }
}

void destrory(object ob)
{
        destruct(ob);
}

