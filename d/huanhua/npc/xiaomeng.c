// xiaomeng.c  萧猛
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("萧猛", ({ "xiao meng", "meng" }));
        set("nickname", HIW "龙" NOR);
        set("long", 
                "这是个年约２０的青年，一身横肉,给人一种威猛的感觉。\n"
                "他所负责的龙组,担负着浣花剑派的保卫工作。\n");
        set("gender", "男性");
        set("age", 22);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 140000);
        set("score", 30000);

        set_skill("force", 70);
       set_skill("unarmed",90);
        set_skill("dodge", 70);
        set_skill("parry",70);
        set_skill("sword", 70);
        set_skill("literate", 60);
        set_skill("strike",60);

        set_skill("huanhua-jian",90);
         set_skill("tiexian-quan",90);
         set_skill("guiyuan-dafa",70);
         set_skill("feihua-wuping",70);

         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");



        create_family("浣花剑派", 3, "弟子");

        set("chat_chance_combat", 40);
            set("no_get",1);
        setup();
        carry_object("/clone/weapon/sword")->wield();
          carry_object("/d/huanhua/obj/ccloth")->wear();

}




void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -50 &&ob->query("family/master_id")=="xiao meng")
        {
                    command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","浣花剑派" + RED + "弃徒" NOR);   
        }

}




void attempt_apprentice(object ob)
{
        if ((int)ob->query_str() > 24) {
        message_vision(HIY"萧猛拍了拍$N的肩膀，满意地看着笑了笑!\n"NOR,ob);
              command("say 好吧！我就收下你做我的弟子了。");
                command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
                ob->set("title","浣花剑派龙组弟子");
        return ;
            }
       else
               message_vision(HIC"萧猛盯着$N看了老半天，叹了口气道:你的身体条件不适合学我的功夫!\n"NOR,ob);
               return ;

 

}


