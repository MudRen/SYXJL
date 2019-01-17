// famu.c ��ľ
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ľ����", ({ "famu daozhang", "famu" }));
        set("long", 
                "�����䵱ɽ�ķ�ľ����, רΪ�����ṩľ�ġ�\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("blade", 60);
        set_skill("taiji-dao", 60);
        set_skill("taiji-quan", 60);
        set_skill("tiyunzong", 60);
        set_skill("taiji-shengong", 60);
        set_skill("taoism", 60);
        set_skill("literate", 60);

        map_skill("blade", "taiji-dao");

        create_family("�䵱��", 4, "����");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
}


void attempt_apprentice(object ob)
{


        if ( this_player()->query("class")=="bonze")
        {
                command("say ���ɲ��շ��ŵ��ӣ�" + RANK_D->query_respect(ob) + "���ֻ�����������");
                return;
        }
        if ( this_player()->query("gender")=="����")
        {
                 command("say ���ɲ���̫�࣬" + RANK_D->query_respect(ob) + "��ذɡ�");
                return;
        }

        if ((string)ob->query("class") != "taoist")
        {
                command("say ����ֻ�յ�ʿ��"+ RANK_D->query_respect(ob) + "�Ƿ�Ը���������塣");
                command("say ���������ˡ��������(decide)��");
                ob->set_temp("prepare/taoist", 1);
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
         command("chat " + ob->query("name") + "�����������䵱�ɡ�");
               command("chat* hehe");
        this_player()->set("class", "taoist");
        if (this_player()->query("age")<20)
        {
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title","�䵱�ɵ�ͯ");
        else
                this_player()->set("title","�䵱��С����");
        }
        else {
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title","�䵱�ɵ�ʿ");
        else
                this_player()->set("title","�䵱�ɵ���");
        }
}

void init()
{

        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<0&&ob->query("family/master_id")=="famu daozhang")
        {
                  command("chat "+ob->query("name")+"!����ɱ��Խ����������Ϊ���������������ʦ����\n");
                  command("expell "+ ob->query("id"));
                  this_player()->set("title","�䵱��" + RED + "��ͽ" NOR);   
        }
}               


int do_decide()
{

        object ob=this_player();
        if( !this_player()->query_temp("prepare/taoist") )
                return 0;
        
        this_player()->delete_temp("prepare/taoist");

        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return 0;
        }
   
        this_player()->set("class", "taoist");
        command("say �ðɣ�ƶ�����������ˡ�");
        command("say ������Ѿ���������ӣ��Ժ����¿�Ҫ�ú����ˣ����������޷����㡣");
        command("recruit " + ob->query("id"));
        if (this_player()->query("age")<20)
        {
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title","�䵱�ɵ�ͯ");
        else
                this_player()->set("title","�䵱��С����");
        }
        else {
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title","�䵱�ɵ�ʿ");
        else
                this_player()->set("title","�䵱�ɵ���");
        }
        return 1;
}


