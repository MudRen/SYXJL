//christmas-man.c 圣诞老人
//by bsd 12/18/2000

#include <ansi.h>

 inherit NPC;
 int ask_me();

 void create()
 {
	set("title",HIC"随缘节日大使"NOR);
        set("nickname",HIW"表哥"HIG"的"HIM"小弟"NOR);
        set_name("圣诞老人",({"Santa claus", "shengdan laoren", "laoren"}));
	set("gender","男性");
        set("age",60);
	set("long",
	         "他就是随缘的节日大使,每当到了快乐的节日,\n"
		 "他就会神秘的出现了,而且总会给大家带些神奇\n"
		 "的礼物,他长的和蔼可亲,一副笑呵呵的样子,让\n"
		 "你情不自禁的想和他接近接近.\n");
	set("attitude","peaceful");
	set("str",40);
	set("int",40);
	set("con",40);
	set("dex",40);
	set("per",28);

	set("chat_chance",1);
	set("chat_msg",({
                HIY"圣诞老人笑呵呵的说道: 圣诞节到了,大家节日快乐啊.\n"NOR,
		HIG"圣诞老人神秘的对你说,想知道有什么礼物吗? ask laoren about 礼物 \n"NOR
	}));


	set("inquiry",([
		"liwu" : (: ask_me :),
		"礼物" : (: ask_me :),
	]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 8000000);
        set("score", 200000);

        set_skill("dodge", 500);                
        set_skill("shenxing-baibian", 500);
        set_skill("parry", 500);
	set_skill("unarmed",500);
	set_skill("force",500);
	set_skill("jiuyang-force",500);                
        
        map_skill("dodge", "shenxing-baibian");
	map_skill("unarmed","jiuyang-force");
	map_skill("force","jiuyang-force");

	setup();

	carry_object("/u/bsd/obj/silver-cloth")->wear();
}


int ask_me()
{
	object ob;
	ob = this_player();
	if(ob->query("shengdan") )
	{command ("shake");
	command ("say 这位"+RANK_D->query_respect(ob)+"小小年纪就贪心啊！小心我老大打你屁屁哦！ ");
	return 1;
	}
        
/*	ob1 = new("/u/bsd/christmas/card");
	ob1->move(ob);
*/
	ob->set("shengdan",1);
  	ob->add("combat_exp",20000);
	ob->add("potential",10000);
        command("chat# 对着" +ob->name(1)+ "说到：“祝你圣诞节快乐,合家幸福。”");
        command("jh# 对着" +ob->name(1)+ "说到：“祝你圣诞节快乐,合家幸福。”");
	return 1;
}

