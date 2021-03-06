#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void consider();

void create()
{
        set_name("任我行", ({ "ren woxing", "ren",}));
        set("long", 
"此人双目精光闪烁，头发须眉都是深黑之色，一眼扫过，不怒自威，
目光中隐隐露出凶霸霸的气势，不是个平常人物。\n");
        set("title",HIB"日月神教现任教主"NOR);         
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 1600);
        set("max_jing", 300);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 120);
        set("combat_exp", 2000000);
        set("shen", -200000);


          set_skill("sword", 300);
            set_skill("tmdafa",240);
          set_skill("parry", 300);
        set_skill("literate",200);
          set_skill("dodge", 300);
          set_skill("unarmed", 300);
          set_skill("whip", 250);
          set_skill("force", 300);
         set_skill("tmzhang", 300);
        set_skill("staff", 160);
         set_skill("tmjian", 290);
         set_skill("tmdao", 300);
        set_skill("rybian",200);
         set_skill("pmshenfa", 300);
        set_skill("wuchang-zhang",100);
         set_skill("xixing-dafa", 290);
          set_skill("strike",300);
         set_skill("blade", 300);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "xixing-dafa");
        map_skill("whip", "rybian");
       create_family("日月神教",1,"弟子");
 set("inquiry", ([
                "吸星大法": (: ask_me :),
                "任盈盈" : "你难道知道她在哪吗？\n",
                "任我行" : "我就是威震江湖的日月神教教主，你就拜我为师吧。\n",
                "日月神教" : "是的！快加入我们神教吧，这样你的武功就没人能敌。\n",
                ]));
        set("book_count", 1);

            set("no_get",1);
        setup();
}
void attempt_apprentice(object ob)
{
         if (ob->query_int() < 30) {
              command("say " + RANK_D->query_respect(ob) +
                        "走开走开，我不想和傻瓜说话。");
                return;
        }
         if (ob->query_dex() < 25) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
        if ((int)ob->query("shen") > -10000) {
                command("say " + RANK_D->query_respect(ob) +
                        "你还不够心狠手辣，我还不能收你。");
                return;
        }
        command("say 哈哈！ 那我就收下你吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","日月神教任教主亲传弟子");
}


int accept_fight(object me)
{
        command("say 你想比武？你够资格吗？");
        command("say 既然这位" + RANK_D->query_respect(me) + "要比武的话，就莫怪我杀你了！"); 
        command("say 看我吸心大法.......");
        command("chat “几经风沙武艺深，奈何到头费长身”...唉！又一个送死的来了！");

        kill_ob(me);
        return 1;        
}

string ask_me()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
                return RANK_D->query_respect(this_player()) + 
                "与本教素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，吸星大法密籍不在我处。";
        add("book_count", -1);
        ob = new(__DIR__"obj/xxdafa");
        ob->move(this_player());
        return HIY"你拿去吧，早日练成魔功，光大日月。"NOR;
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if( ( (int)ob->query("shen") >= 0 || (int)ob->query("score") < 0 ) && ob->query("family/master_id")=="ren woxing" )
        {
                      command("chat "+ob->query("name")+"!黑木崖不要你这没用的东西。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","日月神教" + RED + "弃徒" NOR);   
        }

}

