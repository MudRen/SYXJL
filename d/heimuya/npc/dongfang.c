// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
        set_name("��������", ({ "dongfang bubai", "dongfang",}));
        set("long", 
"����������֮��һλ���춯�أ��������Ĺֽܡ�
�˿�������˺��룬���Ͼ�Ȼʩ��֬�ۣ������Ǽ�����
ʽ���в��У�Ů��Ů����ɫ֮�����㴩����Ů���ϣ�Ҳ
�Ե�̫���ޡ�̫������Щ��\n");
        set("title",HIY"�����������ʹ"NOR);         
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 32);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        set("per", 26);
        
          set("max_qi", 3600);
          set("max_jing", 3000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
set("combat_exp", 2000000);
        set("shen", -10000);


          set_skill("sword", 190); 
          set_skill("parry", 190);
          set_skill("dodge", 190);
          set_skill("whip", 190);
          set_skill("unarmed", 190);
          set_skill("blade", 190);
          set_skill("force", 200);
          set_skill("tmdao", 190);
        set_skill("rybian",80);
          set_skill("tmdafa", 200);
        set_skill("pixie-jian",220);

        map_skill("unarmed", "tmzhang");
map_skill("sword", "pixie-jian");
map_skill("parry", "pixie-jian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
       create_family("�������",3,"����");
          set("inquiry", ([
                        "��������": (: ask_me :),
                ]));
        set("book_count", 1);
        setup();
  carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        

}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "����" )
        {
                command ("say ��......�㻹û���ʸ����ҵ�ͽ�ܡ�");
                return;
        }

        command("say ��...���Ҫ��������̺úøɰ�����");
        command("recruit " + ob->query("id"));
        ob->set("title","������̳���");
}
string ask_me()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����������Ѿ������Ҵ���";
        add("book_count", -1);
        ob = new(__DIR__"obj/kuihua");
        ob->move(this_player());
        return "�ðɣ��Ȿ���������䡹���û�ȥ�úÿ�����";
}

     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if( ( (int)ob->query("shen") >= 0 || (int)ob->query("score") < 0 ) && ob->query("family/master_id")=="dongfang bubai" )
        {
                      command("chat "+ob->query("name")+"!��ľ�²�Ҫ����û�õĶ�����\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","�������" + RED + "��ͽ" NOR);   
        }

}
