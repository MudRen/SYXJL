#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "ben xiang","xiang"}) );
         set("long",
                "����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
                "̫��Ѩ�߸߹����ƺ��������书��\n"
            );
        set("gender", "����" );
        set("class", "bonze");
        set("age", 65);
        set("shen_type", 1);
        set("str", 35);
        set("int", 32);
        set("con", 32);
        set("dex", 32);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 1000000);

        set_skill("force", 200);
        set_skill("kurong-changong", 200);
        set_skill("dodge", 180);
        set_skill("tiannan-bufa", 180);
        set_skill("parry", 180);
        set_skill("finger", 180);
        set_skill("unarmed", 180);
        set_skill("jinyu-quan", 180);
        set_skill("yiyang-zhi", 180);
        set_skill("buddhism", 200);
        set_skill("literate", 150);
        set_skill("sword", 180);
        set_skill("duanjia-jian", 180);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("parry", "jinyu-quan");
        map_skill("finger", "yiyang-zhi");
        map_skill("unarmed", "jinyu-quan");
        map_skill("sword", "duanjia-jian");
        prepare_skill("unarmed","jingyu-quan");
        
        create_family("������", 6, "����");
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({
                 (: perform_action, "sword.tun" :),
                (: perform_action, "sword.ding" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
            })   );
        setup(); 
        carry_object("/clone/weapon/changjian")->wield();        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object(__DIR__"obj/sengrobe")->wear();
}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 0 && ob->query("family/master_id")=="ben xiang")
        {
                command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name; 
        if ((int)ob->query_skill("kurong-changong", 1) < 180) {
                command("say �������������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڿ��������϶��µ㹦��");
                return 0;
        }
        if ((string)ob->query("class") != "bonze") {
                command("say ���Ĳ����׼ҵ��ӣ�ʩ����ذɡ�");
                
                return ;
        } 
        if ((int)ob->query_skill("buddhism", 1) < 180) {
                command("say ����֮�ˣ�����Ϊ�ȣ����������˷��ŵմ�������ѧ�÷�ҵľ���ɡ�");
                command("say �������ķ����棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }        if ((int)ob->query("shen") <70000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }
        if ((int)ob->query("score") <400) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }

        command("chat ����,����...����ɵö���ù�");
        command("party ��ɮ����һͽ��,����Ժ�ú��д衣");
        command("recruit " + ob->query("id"));
        name = ob->query("name");     
        new_name = "��" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation", 7);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����¹��ֱ����� !");
                return ;
}
