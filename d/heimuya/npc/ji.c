#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("����ʩ", ({ "ji wushi", "ji",}));
        set("nickname", "ҹè��");        
        set("long", 
"�����츳������Ŀ����ǿ�����º��ƺ��񣬻�����а����
Ȼ������ʩ����ʵȴ�ǹ�ƶ�ˣ��Ǹ������������\n");
        set("title",HIY"������̹�����ʹ"NOR);         
       set("gender", "����");
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
       create_family("�������",3,"����");

          set("inquiry", ([
                        "��ľ��": (: ask_me :),
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
                        "����Ƿ�ϣ���ѧ������һ���书��");
                return;
        }
         if (ob->query_dex() < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
        if ((int)ob->query("shen") > 100) {
                command("say " + RANK_D->query_respect(ob) +
                        "�������ĺ��������һ��������㡣");
                return;
        }
        command("say �ðɣ��������������ˣ����͸��ű����úõظɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","������̹�����ʹ���µ���");
}



string ask_me()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ���ľ����Ҵ���";
        add("book_count", -1);
        ob = new(__DIR__"obj/heimuling");
        ob->move(this_player());
        return HIY"������ʱһ�գ��ɲ�����㽻�����ˣ������Ϊ֪�ɡ�"NOR;
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="ji wushi")
        {
                      command("chat "+ob->query("name")+"!��ľ�²�Ҫ����û�õĶ�����\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","�������" + RED + "��ͽ" NOR);   
        }

}

