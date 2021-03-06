#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_me();
int accept_fight(object ob);
int checking(object me, object ob);
void create()
{
        set_name("枯荣", ({ "ku rong","ku"}) );
        set("gender", "男性" );
        set("title","天龙寺长老");   
        set("class", "bonze");
        set("age", 80);
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 200);
        set("combat_exp", 2000000);
        set("score", 2000000);

        set_skill("force", 230);
        set_skill("kurong-changong", 230);
        set_skill("dodge", 200);
        set_skill("tiannan-bufa", 200);
        set_skill("parry", 200);
        set_skill("finger", 200);
        set_skill("sword", 200);
        set_skill("duanjia-jian", 200);
        set_skill("liumai-shenjian", 200);
        set_skill("buddhism", 250);
        set_skill("literate", 200);
        set_skill("yiyang-zhi", 200);
        set_skill("unarmed", 200);
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("parry", "liumai-shenjian");
        map_skill("finger", "liumai-shenjian");

        prepare_skill("finger","liumai-shenjian");      
        create_family("天龙寺", 5, "长老");
        set("chat_chance_combat", 90); 
        set("chat_msg_combat", ({
                 (: perform_action, "sword.tun" :),
                (: perform_action, "sword.ding" :),
                 (: perform_action, "finger.tan" :),
                (: perform_action, "finger.feng" :),
                  (: perform_action, "finger.ci" :),
                (: perform_action, "finger.liujian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        })   );
        setup();
        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object(__DIR__"obj/sengrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 100 && ob->query("family/master_id")=="ku rong")
        {
                command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","天龙寺" + RED + "弃徒" NOR);
        }
}

void attempt_apprentice(object ob)
{   
        string name,new_name;
        if((!ob->query("family") || ob->query("family")["family_name"]!="天龙寺"))
        {
                command("say 你非天龙弟子，请恕老衲不能收你。");
                
                return ;
        }      
        if ((int)ob->query_skill("kurong-changong", 1) < 200) {
                command("say 我天龙寺着重内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在枯荣禅功上多下点功夫？");
                return ;
        } 
        if ((int)ob->query_skill("yiyang-zhi", 1) < 180) {
                command("say 本门的六脉神剑乃是以段家一阳指为基础的。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "你的一阳指还不够火候。");
                return ;
        }
        if ((int)ob->query_skill("tiannan-bufa", 1) < 180) {
                command("say 你的轻功好象还不怎么样呀。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在轻功上多下点功夫？");
                return ;
        }
        if ((int)ob->query_skill("buddhism", 1) < 200) {
                command("say 悟禅之人，德义为先，我天龙寺乃佛门嫡传，你先学好佛家的经书吧。");
                command("say 在禅宗心法方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if (ob->query_int() < 35) {
                command("say 我天龙寺武功全靠领悟。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
                return ;
        }
        if ((int)ob->query("shen") <300000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if ((int)ob->query("score") <450) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        command("chat 好啦,起来...你今后可得多多用功");
        command("party 老僧又收一徒弟,大家以后好好切磋。");
        command("recruit " + ob->query("id"));
        name = ob->query("name");     
        new_name = "本" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation", 6);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为天龙寺本字辈弟子 !");
                return ;
}
