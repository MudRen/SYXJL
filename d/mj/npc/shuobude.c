// shuobude.c 说不得
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("说不得",({"shuo bude","shuo"}));
       set("nick",YEL"说不得和尚"NOR);
       set("title",RED"明教五散人"NOR);
        set("long", 
                "他就是明教的五散人之一。\n"
                "他一身僧人打扮，满脸的笑容，这就是明教的护法说不得和尚。\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 25);
        set("int", 28);
        set("con", 24);
        set("dex", 25);
        
        set("max_qi",1600);

        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 200000);
        
        set_skill("sword",80);
        set_skill("dodge",80);
        set_skill("unarmed",60); 
        set_skill("literate",60);
        set_skill("force",80);
        set_skill("shenghuo-shengong",80);
        set_skill("qingyunwu", 80);
        set_skill("shenghuo-jian",80);
        set_skill("shenghuo-quan",80);
        set_skill("parry", 80);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","shenghuo-jian");
        map_skill("parry","shenghuo-jian");
        map_skill("unarmed","shenghuo-quan");
        
        create_family("明教",34,"护法");


        setup();
        carry_object("/clone/misc/cloth")->wear();
        
}



void init()
{
       object ob;

       ::init();

        ob = this_player();
        if( ((int)ob->query("score") < 20 || (int)ob->query("shen") < -10 ) && ob->query("family/master_id")=="shuo bude")
        {
                    command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","明教" + RED + "弃徒" NOR);   
        }

}


void attempt_apprentice(object ob)
{
/*
        if((int)this_player()->query("combat_exp") >=10000){
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，他日必定大有成就，成一代伟业。\n");
        command("recruit " + ob->query("id") );
        ob->set("class", "shizhe");
        command("haha");
        } else
*/
        if((int)this_player()->query("combat_exp") < 10000)
        {
        command("shake");
        command("say 恩，" + RANK_D->query_respect(ob) + 
"需要丰富的实战经验。\n");
                return;
      }
        if ((int)ob->query("shen") < 0) {
                command("say " + RANK_D->query_respect(ob) +
                        "有所不知，我平生最恨奸诈之人，你正气太低，我不能让你进入明教半步。");
                return;
        }
       if ((string)ob->query("family/family_name")!="明教" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "若想拜入我派，你可以先去拜徐达。");
                return;
        }        

        if ((int)ob->query("score") <= 20) {
                command("say 这位" + RANK_D->query_respect(ob) +
          "似乎对我教还不够忠心，我还不能收你。");
                return;
        }

        command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")

        ob->set("class", "shizhe");
}
