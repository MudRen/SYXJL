#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ͯ����", ({ "tong baixiong", "tong",}));
        set("long", 
"һ���뷨��׵����ߣ���Ŀ��࣬˫Ŀ����
�������ƹ������½̷����ã������Ž���
���ж��������\n");
        set("title",HIY"������̷�������"NOR);        
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 1200);
        set("max_jing", 300);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 85);
        set("combat_exp", 1000000);
        set("shen", -1);


       set_skill("sword", 140); 
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set_skill("unarmed", 140);
        set_skill("force",140);
        set_skill("tmzhang",140);
        set_skill("strike", 140);
        set_skill("tmjian",140);
        set_skill("literate", 70);
        set_skill("blade", 140);
        set_skill("pmshenfa",140);
         set_skill("tmdafa",140);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        create_family("�������",3,"����");
        setup();
 carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("parry") < 101) {
                command("say ϰ��֮�ˣ�����Ҫ���û�������"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڻ����м��϶��µ㹦��");
                return;
}
         if (ob->query_dex() < 26) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
        command("say ������ ���Ҿ�������ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","������̷����õ���");
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
           if((int)ob->query("shen") > 1000 &&ob->query("family/master_id")=="tong baixiong")
        {
                      command("chat "+ob->query("name")+"!��ľ�²�Ҫ����û�õĶ�����\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","�������" + RED + "��ͽ" NOR);   
        }

}
