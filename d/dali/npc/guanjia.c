// guanjia.c 管家

#include <ansi.h>
inherit NPC;
inherit F_MASTER; 

string ask_me();
void create()
{
        set_name("管家", ({ "guan jia", "guan" }));
        set("title",  "镇南府管家" );
        set("long", "他是大理国镇南王府管家。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 600);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);
        set("score", 2000);

        set_skill("force", 25);
        set_skill("dodge", 25);
        set_skill("parry", 25);
        set_skill("unarmed", 25);
        set_skill("kurong-changong", 25);
        set_skill("tiannan-bufa", 25);
        set_skill("jinyu-quan", 25);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("unarmed", "jinyu-quan");
        map_skill("parry", "jinyu-quan");
  
        create_family("镇南王府",3, "管家");
 
        set("inquiry", ([
                "秘籍" : (: ask_me :),
        ]));

        set("book_count", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",2 );

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say 拜师？...你......？");
                command("say 我堂堂大理镇南王，怎么能收留你这种邪派人士？你还是请回吧！");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        ob->set("score", (int)ob->query("score")+10);
}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "镇南王府")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的轻功秘籍不在此处。";
        add("book_count", -1);
        ob = new(__DIR__"obj/dodge_book");
        ob->move(this_player());
        return "好吧，这本「天南秘籍」你拿回去好好钻研。";
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<=0&&ob->query("family/master_id")=="duan zhengchun")
        {
                  command("chat "+ob->query("name")+"!你这种败类不配留在王府，给我滚出去。\n");
               command("expell "+ ob->query("id"));
                      this_player()->set("title","镇南王府" + RED + "弃徒" NOR);   
        }
}
