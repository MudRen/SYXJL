#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "xiang wentian", "xiang",}));
        set("long", 
"ֻ������ò���ݣ������������һ�Ի��׳��룬������
ǰ���������һ�ѳ�����\n");
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
create_family("�������", 3, "����");        
setup();
       carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        
}

int accept_object(object who, object ob)
{
  object letter;

  if (ob->query("name") == "��ҩ")
    {
      message_vision("�������$N˵����лл���ˣ���������Ÿ����Ϻ�ľ���и����㡣\n",who);
      letter = new(__DIR__"obj/shuxin");
      letter->move(who);
      return 1;
    }
}
void attempt_apprentice(object ob)
{
         if (ob->query_int() < 25) {
                command("say " + RANK_D->query_respect(ob) +
                        "����Ƿ�ϣ���ѧ������һ���书��");
                return;
        }
         if (ob->query_dex() < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
         if (ob->query_str() < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "�������������߰ɡ�");
                return;
        }
 
 //       if ((int)ob->query("force") < 50) {
//             command("say ϰ��֮�ˣ�����Ҫ���û�������");
//                command("say " + RANK_D->query_respect(ob) +
//           "�Ƿ�Ӧ���ڻ����ڹ��϶��µ㹦��");
//                return;
//        }

       command("say �ðɣ��������������ˣ����͸��ű����úõظɡ�");
        command("recruit " + ob->query("id"));
         ob->set("title","������̹�����ʹ���µ���");
}

     void init()
{
        object ob;

        ::init();

        ob = this_player();
	if((int)ob->query("shen") > 1000 &&ob->query("family/master_id")=="xiang wentian")
        {
			command("chat "+ob->query("name")+"!��ľ�²�Ҫ����û�õĶ�����\n");
			command("expell "+ ob->query("id"));
			ob->set("title","�������" + RED + "��ͽ" NOR);   
        }

}

