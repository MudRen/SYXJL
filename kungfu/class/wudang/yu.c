// yu.c 俞莲舟
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("俞莲舟", ({ "yu lianzhou", "yu" }));
        set("nickname", "武当二侠");
        set("long", 
                "他就是张三丰的二弟子俞莲舟。\n"
                "他今年五十岁，身材魁梧，气度凝重。\n"
                "虽在武当七侠中排名第二，功夫却是最精。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 250000);
        set("score", 80000);

        set_skill("force", 100);
          set_skill("taiji-shengong", 150);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 80);
        set_skill("unarmed", 80);
        set_skill("taiji-quan", 80);
        set_skill("parry", 100);
        set_skill("sword", 130);
        set_skill("taiji-jian", 130);
//      set_skill("taoism", 80);
        set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("武当派", 2, "弟子");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.sui" :),
                (: exert_function, "recover" :),
        }) );
            set("no_get",1);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
       if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
                command("say 我武当乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜我徒谷虚。");
                return;
        }
        if ((int)ob->query("shen") < 1000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，我一定收你。");
                return;
        }
        command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，今天就收下你吧。");
        command("recruit " + ob->query("id"));
}
void init()
{
        object ob;
//        mapping fam;
        ::init();
        ob = this_player();
        if ( (int)ob->query("shen") <100 && (string)ob->query("family/master_id") == "yu lianzhou")
        {
                  command("chat "+ob->query("name")+"!你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","武当派" + RED + "弃徒" NOR);   
        }
}
