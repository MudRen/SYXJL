// luchengfeng.c 



#include <ansi.h>



inherit NPC;

inherit F_MASTER;



//void greeting(object);

void init();





void create()

{

    set_name("½�˷�", ({"lu chengfeng", "lu", "chengfeng"}));

//    set("title",WHT "����ׯׯ��" NOR);    

    set("gender", "����");

    set("age", 40);

    set("long", 

        "���ǹ���ׯ��ׯ��,��ҩʦ����ͽ�ܡ��������������ͽý���ֻ��ϧ�ȶ��ˡ�\n"

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

       

    create_family("�һ���", 2, "����");



       set("inquiry", ([

//           "��ʦ" : "����Ͱ��Ұɡ�", 

           "�һ���" : "��������ʦ����פ�أ�Զ�ں��⡣",

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

       if((string)ob->query("family/family_name")=="�һ���")

          { say(WHT "½��ӢЦ������˵������λ" + RANK_D->query_respect(ob)

            + "�������ˣ�������ɡ���\n" NOR);

            return;

           }

       if(!ob->query("family/family_name"))

          { say(WHT "½��Ӣ����Ц�ݵ�˵������λ" + RANK_D->query_respect(ob)

            + ",��ӭ��������ׯ���͡�\n" NOR);

            return;

           }



}*/



void attempt_apprentice(object ob)

{

	if ((int)ob->query_int() < 25) {

                command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ���һ������书��");

		return;

	}



	command("say �ðɣ��Ҿ��������ˡ�");

	command("recruit " + ob->query("id"));

	if((string)ob->query("class") != "swordsman")

		ob->set("class", "scholar");



	return;



}



