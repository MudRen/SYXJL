inherit NPC;

string ask_me_1(string name);
string ask_me_2(string name);
string ask_me_3();
string ask_me_4();
string ask_me_5();

void create()
{
	set_name("归烟", ({"gui yan",	"yan",}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 26);
	set("int", 26);
	set("con", 26);
	set("dex", 28);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 150000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("kurong-changong", 120);
	set_skill("dodge", 110);
	set_skill("duanjia-shenfa", 110);
	set_skill("sword", 85);
	set_skill("duanjia-jian", 85);
	set_skill("parry", 95);
	set_skill("buddhism", 100);
	set_skill("literate", 90);
        set_skill("unarmed",120);
	map_skill("force", "kurong-changong");
	map_skill("dodge", "duanjia-shenfa");
	map_skill("sword", "duanjia-jian");
	map_skill("parry", "duanjia-jian");

	prepare_skill("sword", "duanjia-jian");

	create_family("天龙寺", 7, "大弟子");
        set("inquiry", ([
		"铁护腕" : (: ask_me_1, "huwan" :),
		"铁护腰" : (: ask_me_1, "huyao" :),
		"皮手套" : (: ask_me_1, "shoutao" :),
		"皮围脖" : (: ask_me_1, "weibo" :),
		"铁指套" : (: ask_me_1, "zhitao" :),
		"僧鞋"   : (: ask_me_1, "sengxie" :),
                "铁背心" : (: ask_me_2, "beixin" :),	
		"金创药" :    (: ask_me_3 :),
		"小还丹" :    (: ask_me_4 :),
		"大还丹" :    (: ask_me_5 :)
	    ]));

	set("huju_count", 50);
	set("beixin_count", 5);

	setup();
        carry_object("/clone/weapon/changjian")->wield();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "天龙寺")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有这样防具吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("huju_count") < 1)
		return "抱歉，你来得不是时候，防具已经发完了。";

	ob = new(__DIR__"obj/" + name);
	ob->move(this_player());

	add("huju_count", -1);

	message_vision("归烟给$N一件" + ob->query("name") + "。\n", this_player());

	return "拿去吧。不过要记住，防具只可防身练武，不可凭此妨害他人。";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "天龙寺")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (query("beixin_count") < 1)
		return "抱歉，你来得不是时候，武器已经发完了。";

	ob = new(__DIR__"obj/" + name);
	ob->move(this_player());

	add("beixin_count", -1);

	message_vision("归烟给$N一件" + ob->query("name") + "。\n", this_player());

	return "拿去吧。不过要记住，铁背心乃是防身宝物，不可凭此妨害他人。";
}

string ask_me_3()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "天龙寺")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if (  present("jin chuangyao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("jin_count") < 1) return "对不起，金创药已经发完了";

	ob = new(__DIR__"obj/jinchuang-yao");
	ob->move(this_player());

	add("jin_count", -1);

	message_vision("$N获得一包金创药。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";

}

string ask_me_4()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "天龙寺")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if (  present("xiaohuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("xiao_count") < 1) return "对不起，小还丹已经发完了";

	ob = new(__DIR__"obj/xiaohuan-dan");
	ob->move(this_player());

	add("xiao_count", -1);

	message_vision("$N获得一颗小还丹。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";

}

string ask_me_5()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "天龙寺")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if (  present("dahuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("da_count") < 1) return "对不起，大还丹已经发完了";

	ob = new(__DIR__"obj/dahuan-dan");
	ob->move(this_player());

	add("da_count", -1);

	message_vision("$N获得一颗大还丹。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";

}



