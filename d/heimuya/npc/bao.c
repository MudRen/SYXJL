#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("�����", ({ "bao dachu", "bao",}));
        set("long", 
"һ��������������ߣ�����ò�������������������յĸ��֡�\n");
        set("title",RED"���������ȸ����"NOR);         
       set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 900);
        set("max_jing", 300);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("shen", -1);


        set_skill("sword", 140); 
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set_skill("unarmed",140);
        set_skill("force",140);
        set_skill("tmzhang",140);
        set_skill("tmjian",140);
        set_skill("tmdao",140);        
        set_skill("pmshenfa",140);
        set_skill("tmdafa",140);
     
   map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
       map_skill("force", "tmdafa");
create_family("�������", 3, "����");


          set("inquiry", ([
              "����" : (: ask_me :),
        ]));

        setup();
       carry_object("/d/city/npc/obj/gangdao")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();          
}

string ask_me()
{
       mapping fam; 

       object ob;
        ob=this_player();
      write( "������������㿴����֪����Щʲô���⡣\n"); 
      if (!(fam = this_player()->query("family")) || fam["family_name"] != "�������")
               return RANK_D->query_respect(this_player()) + 
               "�뱾��������������֪�˻��Ӻ�̸��";
      if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi")) 
        return RANK_D->query_respect(this_player()) + "��Ѫ���㣬����ҽ�ΰ���";
         
       ob->set("eff_jing", (int)ob->query("max_jing"));
       ob->set("jing", (int)ob->query("max_jing"));
       ob->set("eff_qi", (int)ob->query("max_qi"));
       ob->set("qi", (int)ob->query("max_qi"));
       write( HIW "������Ӱٻ����ע��һ������������û���ů����ģ�����ʧȥ����Ѫ���ص������� \n"NOR);

       return "�������������"; 

}

