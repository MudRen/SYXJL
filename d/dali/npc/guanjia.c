// guanjia.c �ܼ�

#include <ansi.h>
inherit NPC;
inherit F_MASTER; 

string ask_me();
void create()
{
        set_name("�ܼ�", ({ "guan jia", "guan" }));
        set("title",  "���ϸ��ܼ�" );
        set("long", "���Ǵ�������������ܼҡ�\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 600);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);
        set("score", 2000);

        set_skill("force", 25);
        set_skill("dodge", 25);
        set_skill("parry", 25);
        set_skill("unarmed", 25);
        set_skill("kurong-changong", 25);
        set_skill("tiannan-bufa", 25);
        set_skill("jinyu-quan", 25);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("unarmed", "jinyu-quan");
        map_skill("parry", "jinyu-quan");
  
        create_family("��������",3, "�ܼ�");
 
        set("inquiry", ([
                "�ؼ�" : (: ask_me :),
        ]));

        set("book_count", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",2 );

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say ��ʦ��...��......��");
                command("say �����ô�������������ô������������а����ʿ���㻹����ذɣ�");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        ob->set("score", (int)ob->query("score")+10);
}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "��������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ��Ṧ�ؼ����ڴ˴���";
        add("book_count", -1);
        ob = new(__DIR__"obj/dodge_book");
        ob->move(this_player());
        return "�ðɣ��Ȿ�������ؼ������û�ȥ�ú����С�";
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<=0&&ob->query("family/master_id")=="duan zhengchun")
        {
                  command("chat "+ob->query("name")+"!�����ְ��಻���������������ҹ���ȥ��\n");
               command("expell "+ ob->query("id"));
                      this_player()->set("title","��������" + RED + "��ͽ" NOR);   
        }
}
