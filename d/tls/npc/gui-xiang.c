
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({"gui xiang", "xiang",}));
        set("long",
                "����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
                "̫��Ѩ�߸߹����ƺ��������书��\n"
        );

//      set("nickname", "");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 50);
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 1300000);
        set("score", 10000);

        set_skill("force", 180);
        set_skill("kurong-changong", 180);
        set_skill("dodge", 150);
        set_skill("tiannan-bufa", 150);
        set_skill("unarmed", 150);
        set_skill("jinyu-quan", 150);
        set_skill("parry", 150);
        set_skill("finger", 150);
        set_skill("yiyang-zhi", 150);
        set_skill("sword", 140);
        set_skill("buddhism", 200);
        set_skill("literate", 120);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("unarmed", "jinyu-quan");
        map_skill("parry", "jinyu-quan");

        prepare_skill("unarmed", "jinyu-quan");

        create_family("������", 7, "����");

        setup();

}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 0 && ob->query("family/master_id")=="gui xiang")
        {
                command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name; 
        if((string)this_player()->query("family/master_id")!="xing lei" )
        {       
                command("say �������ڵ���Ϊ���޷��̳��ҵ��²���\n");
                command("say �㻹����������ʦֶѧϰ�ɡ�\n");       
                return ;
        }
        if ((int)ob->query_skill("kurong-changong", 1) < 150) {
                command("say �������������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڿ��������϶��µ㹦��");
                return ;
        }

        if( (string)ob->query("class")!="bonze" )
        {
                command("say �����ӷ����գ����գ�ʩ������������ҷ��������ܽ䡣\n");
                return ;
        }
        if ((int)ob->query("shen") <50000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }
        if ((int)ob->query("score") <350) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }
                command("chat ����,����...����ɵö���ù�");
        command("partytell ��ɮ����һͽ��,����Ժ�ú��д衣");
        command("recruit " + ob->query("id"));
        name = ob->query("name");
        new_name = "��" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation", 8);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
        return ;

}

