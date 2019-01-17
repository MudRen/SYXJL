// xiaoxueyu.c  ��ѩ��
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_DEALER;

void create()
{
        set_name("��ѩ��", ({ "xiao xueyu", "xueyu" }));
        set("nickname", HIG "��" NOR);
        set("long", 
                "��ѩ��������¥��СŮ��,ƽʱ�������Ǽ��������۰�,�Ǹ����������Ĺ��\n"
                "��ѩ�㸺�����,��������ȫ��佻����ɵ�Ů����.\n");
        set("gender", "Ů��");
        set("age", 21);
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
        set_skill("dodge", 100);
        set_skill("parry",70);
        set_skill("sword", 70);
        set_skill("literate", 120);
        set_skill("strike",70);
        set_skill("huanhua-jian",70);
         set_skill("tiexian-quan",70);
         set_skill("guiyuan-dafa",70);
         set_skill("feihua-wuping",100);
         set_skill("feature",80);

         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");



        create_family("佻�����", 3, "Ů����");

        set("chat_chance_combat", 40);

        setup();
        carry_object("/clone/weapon/sword")->wield();
          carry_object("/clone/misc/cloth")->wear();

}




void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -50 &&ob->query("family/master_id")=="xiao xueyu")
        {
                    command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�ҿɲ�Ը�����ʦ����\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","佻�����" + RED + "��ͽ" NOR);   
        }

}



void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="Ů��")
   {
                message_vision("��ѩ������ͷ������, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
                if((string)ob->query("class") != "swordsmanr")
                        ob->set("class", "swordsman");
       return;}
   else
      {
                message_vision("��ѩ��Ц������˵�������ҿ������Ҵ����˰�?��\n",ob);
       return;}
}

