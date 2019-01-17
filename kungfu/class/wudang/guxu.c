// guxu.c ����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("�������", ({ "guxu daozhang", "guxu" }));
        set("long", 
                "�����������۵ĵ��ӹ��������\n"
                "��������ʮ�꣬�����䵱�ɵ����¡�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);

        set("combat_exp", 70000);
        set("score", 8500);

        set_skill("force", 60);
        set_skill("taiji-shengong", 40);
        set_skill("dodge", 70);
        set_skill("tiyunzong", 50);
        set_skill("unarmed", 60);
        set_skill("taiji-quan", 40);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("taiji-jian", 40);
        set_skill("taoism", 60);
        set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        set("inquiry", 
                ([
                        "���¾�" : (: ask_me :),
                ]));
                                
        set("book_count", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
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
 

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵĵ����澭���ڴ˴���";
        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}



void init()
{

        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="guxu daozhang")
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

