#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
        set("nickname", HIG "邋遢真人" NOR);
        set("long", 
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的灰色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 100);
        set("combat_exp", 2000000);
        set("score", 500000);

        set_skill("force", 300);
        set_skill("taiji-shengong", 300);
        set_skill("dodge", 300);
        set_skill("tiyunzong", 300);
        set_skill("unarmed", 320);
        set_skill("taiji-quan", 320);
        set_skill("parry", 300);
        set_skill("sword", 320);
        set_skill("taiji-jian", 320);
        set_skill("blade", 300);
        set_skill("taiji-dao", 300);
        set_skill("taoism", 300);
        set_skill("literate", 200);

        set_skill("fliangyi-jian", 300);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        map_skill("blade", "taiji-dao");

        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.jielidali" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
                command("say 我武当乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先入我道。"); 
                return;
        }
        if ((int)ob->query_skill("taiji-shengong", 1) < 150) {
                command("say 我武当派乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
        if ((int)ob->query("shen") < 100000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if (ob->query_int() < 30) {
                command("say 我武当派武功全从道藏悟出。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
                return;
        }
        command("chat 哈哈哈哈！！！！");
        command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
        command("chat* pat " + ob->query("id"));
        
        command("recruit " + ob->query("id"));
        ob->set("title",HIW"武当张真人亲传弟子"NOR);}


void init()
{

        object ob;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <5000 && (string)ob->query("family/master_id") == "zhang sanfeng")
        {
                  command("chat "+ob->query("name")+"!你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","武当派" + RED + "弃徒" NOR);   
                
        }
}


void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "zhang sanfeng" || arg == "zhang")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

       
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;  
}
