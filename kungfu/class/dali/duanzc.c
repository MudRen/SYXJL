// duanzc.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("段正淳", ({ "duan zhengchun", "duan" }));
        set("nickname", HIY "大理镇南王" NOR );
        set("long", 
                "他就是赫赫有名的大理镇南王，当今大理保定帝的亲兄弟段正淳。\n"
                "他身着一套华丽的服装。\n"
                "他看来已经四十出头，身材瘦小，可以看出他年轻时一定很俊美。\n");
        set("title", "镇南王府王爷");
        set("gender", "男性");
        set("age", 41);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        set("per", 28);
        set("max_qi", 5000);
       set("max_jing", 4000);
       set("neili", 7000);
       set("max_neili", 7000);
        set("jiali", 100);
        set("combat_exp", 800000);
        set("score", 5000);
        set("shen", 50000);
 
       set_skill("buddhism", 120);
       set_skill("force", 100);
        set_skill("tiannan-bufa", 100);
        set_skill("dodge", 100);
        set_skill("jinyu-quan", 100);
        set_skill("strike", 100);
        set_skill("yiyang-zhi", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("duanjia-jian", 100);
        set_skill("literate", 150);
        set_skill("cuff", 100);
        set_skill("kurong-changong", 130);
        set_skill("finger", 100);
        set_skill("wuluo-zhang", 100);
 
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("strike", "wuluo-zhang");
        map_skill("sword", "duanjia-jian");
        map_skill("finger", "yiyang-zhi");
        map_skill("parry", "wuluo-zhang");
        prepare_skill("strike", "wuluo-zhang");

        create_family("镇南王府",1, "王爷");

        set("inquiry", ([
                "秘籍" : (: ask_me :),
        ]));

        set("book_count", 1);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "strike.duansi" :),
                (: perform_action, "strike.xiangsi" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object(__DIR__"obj/hlcloth")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("score") < 200) {
                command("say 拜师？...你......？");
                command("say 我堂堂大理镇南王，怎么能收留你这种邪派人士？你还是请回吧！");
                return;
        }
 
        if (((int)ob->query_skill("force",1) < 70) || ((int)ob->query_skill("kurong-changong",1) < 80))
        {
                command("say 我看" + RANK_D->query_respect(ob) + "的内功修为还略显不足吧。");
                return;
        }
        if (((int)ob->query_skill("sword",1) < 70) || ((int)ob->query_skill("duanjia-jian",1) < 70))
        {
                command("say 我看" + RANK_D->query_respect(ob) + "的段家剑法还没学到家吧。");
                return;
        }
        if (((int)ob->query_skill("dodge",1) < 70) || ((int)ob->query_skill("tiannan-bufa",1) < 70))
        {
                command("say 我看" + RANK_D->query_respect(ob) + "的天南步法还需多点努力。");
                return;
        } 
        if ((int)ob->query_skill("literate", 1) < 70)
        {      
                command("say 我看"  + RANK_D->query_respect(ob) + "，你修养还略现不足。");                command("say 本王是不会收你这种粗人的。");
                return;
        }        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        ob->set("title", "大理镇南王府贴身侍卫");
                         ob->set("class", "guard");
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
        ob = new(__DIR__"obj/finger_book");
        ob->move(this_player());
        return "好吧，这本「一阳秘籍」你拿回去好好钻研。";
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<=100&&ob->query("family/master_id")=="duan zhengchun")
        {
                  command("chat "+ob->query("name")+"!你这种败类不配留在王府，给我滚出去。\n");
               command("expell "+ ob->query("id"));
                      this_player()->set("title","镇南王府" + RED + "弃徒" NOR);   
        }
}

