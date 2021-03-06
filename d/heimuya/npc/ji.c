#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("计无施", ({ "ji wushi", "ji",}));
        set("nickname", "夜猫子");        
        set("long", 
"此人天赋异禀，目力特强，行事忽善忽恶，或正或邪，虽
然名计无施，其实却是诡计多端，是个极厉害的人物。\n");
        set("title",HIY"日月神教光明右使"NOR);         
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
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("combat_exp", 2000000);



        set_skill("sword", 160); 
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("unarmed", 160);
        set_skill("literate", 140);
        set_skill("force",160);
        set_skill("tmzhang",160);
        set_skill("whip", 140);
        set_skill("tmjian",160);
        set_skill("blade", 160);
        set_skill("tmdao",160);        
        set_skill("rybian",160);
        set_skill("pmshenfa",160);
        set_skill("wuchang-zhang",60);
         set_skill("tmdafa",160);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
       create_family("日月神教",3,"弟子");

          set("inquiry", ([
                        "黑木令": (: ask_me :),
                ]));
        set("book_count", 1);
            set("no_get",1);
        setup();
 carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        

}

void attempt_apprentice(object ob)
{
         if (ob->query_int() < 24) {
                command("say " + RANK_D->query_respect(ob) +
                        "天资欠聪，难学得我这一身武功。");
                return;
        }
         if (ob->query_dex() < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
        if ((int)ob->query("shen") > 100) {
                command("say " + RANK_D->query_respect(ob) +
                        "还不够心狠手辣，我还不能收你。");
                return;
        }
        command("say 好吧，本座就收下你了，今后就跟着本座好好地干。");
        command("recruit " + ob->query("id"));
        ob->set("title","日月神教光明右使座下第子");
}



string ask_me()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
                return RANK_D->query_respect(this_player()) + 
                "与本教素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，黑木令不在我处。";
        add("book_count", -1);
        ob = new(__DIR__"obj/heimuling");
        ob->move(this_player());
        return HIY"此牌限时一日，可不能随便交给别人，你好自为知吧。"NOR;
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="ji wushi")
        {
                      command("chat "+ob->query("name")+"!黑木崖不要你这没用的东西。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","日月神教" + RED + "弃徒" NOR);   
        }

}

