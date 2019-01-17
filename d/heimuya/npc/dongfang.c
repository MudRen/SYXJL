// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
        set_name("东方不败", ({ "dongfang bubai", "dongfang",}));
        set("long", 
"他就是武林之中一位惊天动地，威震当世的怪杰。
此刻他剃光了胡须，脸上竟然施了脂粉，身上那件衣衫
式样男不男，女不女，颜色之妖，便穿在少女身上，也
显得太娇艳、太刺眼了些。\n");
        set("title",HIY"日月神教掌旗使"NOR);         
        set("gender", "无性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 32);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        set("per", 26);
        
          set("max_qi", 3600);
          set("max_jing", 3000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
set("combat_exp", 2000000);
        set("shen", -10000);


          set_skill("sword", 190); 
          set_skill("parry", 190);
          set_skill("dodge", 190);
          set_skill("whip", 190);
          set_skill("unarmed", 190);
          set_skill("blade", 190);
          set_skill("force", 200);
          set_skill("tmdao", 190);
        set_skill("rybian",80);
          set_skill("tmdafa", 200);
        set_skill("pixie-jian",220);

        map_skill("unarmed", "tmzhang");
map_skill("sword", "pixie-jian");
map_skill("parry", "pixie-jian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
       create_family("日月神教",3,"弟子");
          set("inquiry", ([
                        "葵花宝典": (: ask_me :),
                ]));
        set("book_count", 1);
        setup();
  carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        

}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "无性" )
        {
                command ("say 哼......你还没有资格做我的徒弟。");
                return;
        }

        command("say 嗯...你可要在日月神教好好干啊！。");
        command("recruit " + ob->query("id"));
        ob->set("title","日月神教长老");
}
string ask_me()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
                return RANK_D->query_respect(this_player()) + 
                "与本教素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，葵花宝典已经不在我处。";
        add("book_count", -1);
        ob = new(__DIR__"obj/kuihua");
        ob->move(this_player());
        return "好吧，这本「葵花宝典」你拿回去好好看看。";
}

     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if( ( (int)ob->query("shen") >= 0 || (int)ob->query("score") < 0 ) && ob->query("family/master_id")=="dongfang bubai" )
        {
                      command("chat "+ob->query("name")+"!黑木崖不要你这没用的东西。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","日月神教" + RED + "弃徒" NOR);   
        }

}
