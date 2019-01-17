// luchengfeng.c 



#include <ansi.h>



inherit NPC;

inherit F_MASTER;



//void greeting(object);

void init();





void create()

{

    set_name("陆乘风", ({"lu chengfeng", "lu", "chengfeng"}));

//    set("title",WHT "归云庄庄主" NOR);    

    set("gender", "男性");

    set("age", 40);

    set("long", 

        "这是归云庄的庄主,黄药师的三徒弟。长身玉立，身型矫健，只可惜腿断了。\n"

        );



    set("attitude", "peaceful");

      

    set("str", 24);

    set("int", 20);

    set("con", 21);

    set("dex", 20);



    set("qi", 800);

    set("max_qi", 800);

    set("jing", 200);

    set("max_jing", 200);

    set("neili", 500);

    set("max_neili", 500);

    set("jiali", 30);

       

    set("combat_exp", 80000);

    set("score", 0);

       

    set_skill("force", 80);

    set_skill("bibo-shengong", 80);

    set_skill("unarmed", 80);

    set_skill("luoying-zhang", 75);

    set_skill("dodge", 80);

    set_skill("anying-fuxiang", 80);

    set_skill("parry", 80);

    set_skill("sword", 80);

    set_skill("luoying-shenjian",80);

    set_skill("literate", 80);

    set_skill("qimen-wuxing",80);

   

    map_skill("force"  , "bibo-shengong");

    map_skill("unarmed", "luoying-zhang");

    map_skill("dodge"  , "anying-fuxiang");

    map_skill("sword"  , "luoying-shenjian") ;

       

    create_family("桃花岛", 2, "弟子");



       set("inquiry", ([

//           "拜师" : "那你就拜我吧。", 

           "桃花岛" : "那是我派师父的驻地，远在海外。",

            ]) );



    setup();



    carry_object("/d/taohua/obj/baipao")->wear();

    carry_object("/clone/weapon/changjian")->wield();

 }



/*void init()

{

       object ob;



       ::init();



       if( interactive(ob = this_player()) && !is_fighting() ) {

               remove_call_out("greeting");

               call_out("greeting", 1, ob);

       }

}

void greeting(object ob)

{

       if( !ob || environment(ob) != environment() ) return;

       if((string)ob->query("family/family_name")=="桃花岛")

          { say(WHT "陆冠英笑吟吟地说道：这位" + RANK_D->query_respect(ob)

            + "您辛苦了，快请进吧　。\n" NOR);

            return;

           }

       if(!ob->query("family/family_name"))

          { say(WHT "陆冠英满脸笑容地说道：这位" + RANK_D->query_respect(ob)

            + ",欢迎您到归云庄做客。\n" NOR);

            return;

           }



}*/



void attempt_apprentice(object ob)

{

	if ((int)ob->query_int() < 25) {

                command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我桃花岛的武功？");

		return;

	}



	command("say 好吧，我就收下你了。");

	command("recruit " + ob->query("id"));

	if((string)ob->query("class") != "swordsman")

		ob->set("class", "scholar");



	return;



}



