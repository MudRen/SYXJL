// lu chengfeng.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void init();
string ask_me_jiuwan();

void create()
{
    set_name("陆乘风", ({"lu chengfeng", "lu", "chengfeng"}));
    set("title",WHT "归云庄庄主" NOR);    
    set("gender", "男性");
    set("age", 45);
    set("long", 
        "这是归云庄的庄主。早年因陈玄风和梅超风二人盗取九阴真经而被打断了双腿,所以行动不便。\n"
        );

    set("attitude", "peaceful");
      
    set("str", 22);
    set("int", 28);
    set("con", 23);
    set("dex", 25);

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 700);
    set("max_jing", 700);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 40);
       
    set("combat_exp", 500000);
    set("score", 0);
       
    set_skill("force", 120);
    set_skill("bibo-shengong", 120);
    set_skill("unarmed", 120); 
    set_skill("strike", 120);    set_skill("luoying-zhang", 120);
    set_skill("dodge", 100);
    set_skill("anying-fuxiang", 120);
    set_skill("parry", 120);
    set_skill("sword", 140);
    set_skill("luoying-shenjian",140);
    set_skill("literate", 100);
    set_skill("qimen-wuxing",120);
   
    map_skill("force"  , "bibo-shengong");
    map_skill("strike", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("桃花岛", 2, "弟子");
       set("inquiry", ([
                "九花玉露丸" :    (: ask_me_jiuwan :)
        ]));
       set("jiu_count",10);     

       
    setup();

    carry_object(__DIR__"obj/bupao")->wear();
    carry_object(__DIR__"obj/changjian")->wield();
 }

void init()
{
       object ob;

       ::init();

       if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        ob = this_player();
        if((int)ob->query("score")<=-50&&ob->query("family/master_id")=="lu chengfeng")
        {
                    command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","桃花岛" + RED + "弃徒" NOR);   
        }

       }
}

void attempt_apprentice(object ob)
{
        
        if ((int)ob->query_int() < 25) {
                command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我桃花岛武功？");
                return;
        }

        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        return;
}

string ask_me_jiuwan()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "桃花岛")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

        if (  present("jiuhua wan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";

        if (query("jiu_count") < 1) return "对不起，九花玉露丸已经发完了";

        ob = new("/d/taohua/obj/jiuwan");
        ob->move(this_player());

        add("jiu_count", -1);

        message_vision("$N获得一颗九花玉露丸。\n",this_player());
        return "好吧，记住，不到危急关头不要轻易使用此药。";

}

