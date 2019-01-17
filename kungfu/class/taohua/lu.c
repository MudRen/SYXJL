// lu chengfeng.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void init();
string ask_me_jiuwan();

void create()
{
    set_name("½�˷�", ({"lu chengfeng", "lu", "chengfeng"}));
    set("title",WHT "����ׯׯ��" NOR);    
    set("gender", "����");
    set("age", 45);
    set("long", 
        "���ǹ���ׯ��ׯ����������������÷������˵�ȡ�����澭���������˫��,�����ж����㡣\n"
        );

    set("attitude", "peaceful");
      
    set("str", 22);
    set("int", 28);
    set("con", 23);
    set("dex", 25);

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 700);
    set("max_jing", 700);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 40);
       
    set("combat_exp", 500000);
    set("score", 0);
       
    set_skill("force", 120);
    set_skill("bibo-shengong", 120);
    set_skill("unarmed", 120); 
    set_skill("strike", 120);    set_skill("luoying-zhang", 120);
    set_skill("dodge", 100);
    set_skill("anying-fuxiang", 120);
    set_skill("parry", 120);
    set_skill("sword", 140);
    set_skill("luoying-shenjian",140);
    set_skill("literate", 100);
    set_skill("qimen-wuxing",120);
   
    map_skill("force"  , "bibo-shengong");
    map_skill("strike", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("�һ���", 2, "����");
       set("inquiry", ([
                "�Ż���¶��" :    (: ask_me_jiuwan :)
        ]));
       set("jiu_count",10);     

       
    setup();

    carry_object(__DIR__"obj/bupao")->wear();
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
        if((int)ob->query("score")<=-50&&ob->query("family/master_id")=="lu chengfeng")
        {
                    command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","�һ���" + RED + "��ͽ" NOR);   
        }

       }
}

void attempt_apprentice(object ob)
{
        
        if ((int)ob->query_int() < 25) {
                command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ���һ����书��");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        return;
}

string ask_me_jiuwan()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�һ���")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

        if (  present("jiuhua wan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

        if (query("jiu_count") < 1) return "�Բ��𣬾Ż���¶���Ѿ�������";

        ob = new("/d/taohua/obj/jiuwan");
        ob->move(this_player());

        add("jiu_count", -1);

        message_vision("$N���һ�žŻ���¶�衣\n",this_player());
        return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}

