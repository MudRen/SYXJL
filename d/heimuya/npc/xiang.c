#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("向问天", ({ "xiang wentian", "xiang",}));
        set("long", 
"只见他容貌清瘦，颏下疏疏朗朗一丛花白长须，垂在胸
前，腰间挂着一把长剑。\n");
        set("title",HIY"日月神教光明左使"NOR);        
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
        set("score", -5000);


        set_skill("sword", 160); 
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("unarmed", 160);
        set_skill("blade", 160);
        set_skill("force",160);
        set_skill("strike", 160);
        set_skill("literate", 80);
        set_skill("tmzhang",160);
        set_skill("tmjian",160);
        set_skill("tmdao",160);        
        set_skill("rybian",60);
        set_skill("pmshenfa",160);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
create_family("日月神教", 3, "弟子");        
setup();
       carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        
}

int accept_object(object who, object ob)
{
  object letter;

  if (ob->query("name") == "金创药")
    {
      message_vision("向问天对$N说到：谢谢你了，我这封书信给你上黑木崖行个方便。\n",who);
      letter = new(__DIR__"obj/shuxin");
      letter->move(who);
      return 1;
    }
}
void attempt_apprentice(object ob)
{
         if (ob->query_int() < 25) {
                command("say " + RANK_D->query_respect(ob) +
                        "天资欠聪，难学得我这一身武功。");
                return;
        }
         if (ob->query_dex() < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
         if (ob->query_str() < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "臂力不够，请走吧。");
                return;
        }
 
 //       if ((int)ob->query("force") < 50) {
//             command("say 习武之人，最主要练好基本功。");
//                command("say " + RANK_D->query_respect(ob) +
//           "是否还应该在基本内功上多下点功夫？");
//                return;
//        }

       command("say 好吧，本座就收下你了，今后就跟着本座好好地干。");
        command("recruit " + ob->query("id"));
         ob->set("title","日月神教光明左使座下弟子");
}

     void init()
{
        object ob;

        ::init();

        ob = this_player();
	if((int)ob->query("shen") > 1000 &&ob->query("family/master_id")=="xiang wentian")
        {
			command("chat "+ob->query("name")+"!黑木崖不要你这没用的东西。\n");
			command("expell "+ ob->query("id"));
			ob->set("title","日月神教" + RED + "弃徒" NOR);   
        }

}

