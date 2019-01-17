// xiaoren.c  ����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_DEALER;

void create()
{
        set_name("����", ({ "xiao ren", "ren" }));
        set("nickname", HIR "ӥ" NOR);
        set("long", 
                "���Ǹ���Լ3�������꣬���ݵ����,һ˫�������۾���ͣ��ɨ�������ҡ�\n"
                "���������ӥ��,������佻����ɵ���칤����\n");
        set("gender", "����");
        set("age", 29);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 140000);
        set("score", 30000);

        set_skill("force", 70);
       set_skill("unarmed",70);
        set_skill("dodge", 90);
        set_skill("parry",70);
        set_skill("sword", 70);
        set_skill("literate", 120);
        set_skill("strike",70);

        set_skill("huanhua-jian",80);
         set_skill("tiexian-quan",80);
         set_skill("guiyuan-dafa",80);
         set_skill("feihua-wuping",80);

         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");


        create_family("佻�����", 3, "����");

        set("chat_chance_combat", 40);
            set("no_get",1);
        setup();
        carry_object("/clone/weapon/sword")->wield();
        carry_object(__DIR__"obj/ccloth")->wear();

}





void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -50 &&ob->query("family/master_id")=="xiao ren")
        {
                    command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","佻�����" + RED + "��ͽ" NOR);   
        }

}



void attempt_apprentice(object ob)
{
        if ((int)ob->query_dex() > 24) {
        message_vision(HIY"����������$N�ļ������ؿ���Ц��Ц!\n"NOR,ob);
              command("say �ðɣ��Ҿ����������ҵĵ����ˡ�");
                command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
                ob->set("title","佻�����ӥ�����");
        return ;
            }
       else
               message_vision(HIC"���Ͷ���$N�����ϰ��죬̾�˿�����:��������������ʺ�ѧ�ҵĹ���!\n"NOR,ob);
               return ;

 

}

