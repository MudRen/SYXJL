// luguanying.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();


void create()
{
    set_name("½��Ӣ", ({"lu guanying", "lu", "guanying"}));
    set("title",WHT "����ׯ��ׯ��" NOR);    
    set("gender", "����");
    set("age", 23);
    set("long", 
        "���ǹ���ׯ����ׯ�����������������ͽý��������������˵ĳ�����\n"
        );

    set("attitude", "peaceful");
      
    set("str", 24);
    set("int", 20);
    set("con", 21);
    set("dex", 20);

    set("qi", 300);
    set("max_qi", 300);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 300);
    set("max_neili", 300);
    set("jiali", 0);
       
    set("combat_exp", 50000);
    set("score", 0);
       
    set_skill("force", 60);
    set_skill("bibo-shengong", 60);
    set_skill("unarmed", 50);
    set_skill("luoying-zhang", 40);
    set_skill("dodge", 50);
    set_skill("anying-fuxiang", 50);
    set_skill("parry", 45);
    set_skill("sword", 40); 
    set_skill("strike", 40);    set_skill("luoying-shenjian",40);
    set_skill("literate", 40);
    set_skill("qimen-wuxing",40);
   
    map_skill("force"  , "bibo-shengong");
    map_skill("strike", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("�һ���", 3, "����");

       set("inquiry", ([
           "��ʦ" : "����Ͱ��Ұɡ�", 
           "�һ���" : "��������ʦ����פ�أ�Զ�ں��⡣",
            ]) );

    setup();

    carry_object(__DIR__"obj/baipao")->wear();
    carry_object(__DIR__"obj/changjian")->wield();
 }
void init()
{
       object ob;

       ::init();

       if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        ob = this_player();
          if((int)ob->query("score")<=-50&&ob->query("family/master_id")=="lu guanying")
        {
                    command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","�һ���" + RED + "��ͽ" NOR);   
        }

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

}

void attempt_apprentice(object ob)
{
     command("say �ðɣ��������㡣\n");
     command("recruit "+ob->query("id"));
     command("say ������ȥ��Ϣһ�°ɡ�\n");
     return;
}


