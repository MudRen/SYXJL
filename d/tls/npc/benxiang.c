#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("本相", ({ "ben xiang","xiang"}) );
         set("long",
                "他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
                "太阳穴高高鼓起，似乎身怀绝世武功。\n"
            );
        set("gender", "男性" );
        set("class", "bonze");
        set("age", 65);
        set("shen_type", 1);
        set("str", 35);
        set("int", 32);
        set("con", 32);
        set("dex", 32);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 1000000);

        set_skill("force", 200);
        set_skill("kurong-changong", 200);
        set_skill("dodge", 180);
        set_skill("tiannan-bufa", 180);
        set_skill("parry", 180);
        set_skill("finger", 180);
        set_skill("unarmed", 180);
        set_skill("jinyu-quan", 180);
        set_skill("yiyang-zhi", 180);
        set_skill("buddhism", 200);
        set_skill("literate", 150);
        set_skill("sword", 180);
        set_skill("duanjia-jian", 180);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("parry", "jinyu-quan");
        map_skill("finger", "yiyang-zhi");
        map_skill("unarmed", "jinyu-quan");
        map_skill("sword", "duanjia-jian");
        prepare_skill("unarmed","jingyu-quan");
        
        create_family("天龙寺", 6, "弟子");
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({
                 (: perform_action, "sword.tun" :),
                (: perform_action, "sword.ding" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
            })   );
        setup(); 
        carry_object("/clone/weapon/changjian")->wield();        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object(__DIR__"obj/sengrobe")->wear();
}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 0 && ob->query("family/master_id")=="ben xiang")
        {
                command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","天龙寺" + RED + "弃徒" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name; 
        if ((int)ob->query_skill("kurong-changong", 1) < 180) {
                command("say 我天龙寺着重内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在枯荣禅功上多下点功夫？");
                return 0;
        }
        if ((string)ob->query("class") != "bonze") {
                command("say 老衲不收俗家弟子，施主请回吧。");
                
                return ;
        } 
        if ((int)ob->query_skill("buddhism", 1) < 180) {
                command("say 悟禅之人，德义为先，我天龙寺乃佛门嫡传，你先学好佛家的经书吧。");
                command("say 在禅宗心法方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }        if ((int)ob->query("shen") <70000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if ((int)ob->query("score") <400) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }

        command("chat 好啦,起来...你今后可得多多用功");
        command("party 老僧又收一徒弟,大家以后好好切磋。");
        command("recruit " + ob->query("id"));
        name = ob->query("name");     
        new_name = "归" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation", 7);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为天龙寺归字辈弟子 !");
                return ;
}
