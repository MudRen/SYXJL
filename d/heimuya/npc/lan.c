#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me1();
string ask_me2();

void create()
{
        set_name("�����", ({ "lan fenghuang", "lan",}));
        set("long", 
"��Ů�Ӽ���΢�ƣ�˫�ۼ��󣬺�����ᡣ
���ƹ����½����置���������嶾�̡���
ʹ���ַ��������أ����˷���ʤ����\n");
        set("title",HIC"��������嶾ʥ��"NOR);        
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        set("combat_exp", 1000000);
        set_skill("unarmed",100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("blade", 100);
        set_skill("literate", 70);
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);
         set_skill("feature",150);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        create_family("�������",3,"����");
          set("inquiry", ([
                        "�Ի���": (: ask_me1 :),
                        "����": (: ask_me2 :),
                ]));
        set("book_count", 1);


        setup();
        carry_object(__DIR__"obj/cloth")->wear();        

}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
        {
                command ("say �Բ�����ֻ��Ů���ӡ�");
                return;
        }

        command("say �ף������СŮ����Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
if( (string)ob->query("class") != "dancer")
ob->set("class", "dancer");
        ob->set("title","��������嶾ʥŮ");
}



string ask_me1()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ��Ի��㲻���Ҵ���";
        add("book_count", -1);
        ob = new(__DIR__"obj/yao");
        ob->move(this_player());
 return (RANK_D->query_respect(ob) +
                   "���滵����Ҫ�����������������Ŷ��");
}

string ask_me2()
 {
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ﲻ���Ҵ���";
        add("book_count", -1);
        ob = new(__DIR__"obj/yuxiao");
        ob->move(this_player());
 return (RANK_D->query_respect(ob) +
                   "�����ͼ��ˣ����Ҫ�úñ���Ŷ��");
}
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="lan fenghuang")
        {
                      command("chat "+ob->query("name")+"!��ľ�²�Ҫ����û�õĶ�����\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","�������" + RED + "��ͽ" NOR);   
        }

}

