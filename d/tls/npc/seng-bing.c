#include <ansi.h>

inherit NPC;

void create()
{
	set_name("守寺僧兵", ({ "seng bing","seng","bing",}));
	set("long",
		"他是一位身材高大的壮年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 50);
	set("combat_exp", 10000);
	set("score", 1);

	set_skill("force", 50);
	set_skill("kurong-changong", 50);
	set_skill("dodge", 70);
	set_skill("duanjia-shenfa", 70);
	set_skill("duanjia-jian", 60);
	set_skill("sword", 60);
	set_skill("parry", 50);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "duanjia-shenfa");
	map_skill("sword", "duanjia-jian");
	map_skill("parry", "duanjia-jian");

	setup();

	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ( (fam = ob->query("family")) && fam["family_name"] != "天龙寺" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say 你是谁？  怎么闯到天龙寺寺里来了？！");
			command("say 快给我速速离开，下次看到决不轻饶！");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，竟敢闯到天龙寺里来撒野！！！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
