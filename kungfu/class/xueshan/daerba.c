// /kungfu/class/xueshan/daerba.c  达而巴
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("达而巴", ({ "daerba huofo", "huofo" }));
        set("long",@LONG
他是金轮法王座下的大弟子。深得法王的真传。
身穿一件黄色袈裟，头带僧帽。
LONG
        );
        set("title", HIY "活佛" NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 150000);

        set_skill("mizong-xinfa", 80);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 120);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 100);
        set_skill("unarmed", 100);
        set_skill("yujiamu-quan", 80);
        set_skill("parry", 100);
        set_skill("sword", 70);
        set_skill("mingwang-jian", 60);
        set_skill("hammer", 120);
        set_skill("riyue-lun", 100 );


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");

        create_family("雪山寺", 3, "活佛");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/yinlun")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("gold",5);
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
           if((int)ob->query("score")< -51&&ob->query("family/master_id")=="daerba huofo")
        {
                      command("chat "+ob->query("name")+"! 装什么正道人士，从此以后你就不要再到雪山寺来了! \n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","雪山寺" + RED + "弃徒" NOR);   
        }
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

         if ((string)ob->query("class") != "bonze") {
                command("say 我佛门的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
        }

        if ((int)ob->query_skill("mizong-xinfa", 1) < 60) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的心法？");
                return;
        }

        command("say 你就是我的弟子了！");
        command("recruit " + ob->query("id"));

        ob->set("title","大喇嘛");
}

