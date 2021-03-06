#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me1();
string ask_me2();

void create()
{
        set_name("蓝凤凰", ({ "lan fenghuang", "lan",}));
        set("long", 
"这女子肌肤微黄，双眼极大，黑如点漆。
她掌管日月教在苗疆的下属“五毒教”，
使毒手法诡秘奇特，令人防不胜防。\n");
        set("title",HIC"日月神教五毒圣姑"NOR);        
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        set("combat_exp", 1000000);
        set_skill("unarmed",100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("blade", 100);
        set_skill("literate", 70);
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);
         set_skill("feature",150);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        create_family("日月神教",3,"弟子");
          set("inquiry", ([
                        "迷魂香": (: ask_me1 :),
                        "玉箫": (: ask_me2 :),
                ]));
        set("book_count", 1);


        setup();
        carry_object(__DIR__"obj/cloth")->wear();        

}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "女性" )
        {
                command ("say 对不起，我只收女弟子。");
                return;
        }

        command("say 咦，不错的小女孩嘛，我就收下你了。");
        command("recruit " + ob->query("id"));
if( (string)ob->query("class") != "dancer")
ob->set("class", "dancer");
        ob->set("title","日月神教五毒圣女");
}



string ask_me1()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
                return RANK_D->query_respect(this_player()) + 
                "与本教素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，迷魂香不在我处。";
        add("book_count", -1);
        ob = new(__DIR__"obj/yao");
        ob->move(this_player());
 return (RANK_D->query_respect(ob) +
                   "可真坏，可要用在你的心上人身上哦。");
}

string ask_me2()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
                return RANK_D->query_respect(this_player()) + 
                "与本教素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，玉箫不在我处。";
        add("book_count", -1);
        ob = new(__DIR__"obj/yuxiao");
        ob->move(this_player());
 return (RANK_D->query_respect(ob) +
                   "宝箫送佳人，你可要好好保管哦。");
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="lan fenghuang")
        {
                      command("chat "+ob->query("name")+"!黑木崖不要你这没用的东西。\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","日月神教" + RED + "弃徒" NOR);   
        }

}

