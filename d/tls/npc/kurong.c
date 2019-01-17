#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_me();
int accept_fight(object ob);
int checking(object me, object ob);
void create()
{
        set_name("����", ({ "ku rong","ku"}) );
        set("gender", "����" );
        set("title","�����³���");   
        set("class", "bonze");
        set("age", 80);
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 200);
        set("combat_exp", 2000000);
        set("score", 2000000);

        set_skill("force", 230);
        set_skill("kurong-changong", 230);
        set_skill("dodge", 200);
        set_skill("tiannan-bufa", 200);
        set_skill("parry", 200);
        set_skill("finger", 200);
        set_skill("sword", 200);
        set_skill("duanjia-jian", 200);
        set_skill("liumai-shenjian", 200);
        set_skill("buddhism", 250);
        set_skill("literate", 200);
        set_skill("yiyang-zhi", 200);
        set_skill("unarmed", 200);
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("parry", "liumai-shenjian");
        map_skill("finger", "liumai-shenjian");

        prepare_skill("finger","liumai-shenjian");      
        create_family("������", 5, "����");
        set("chat_chance_combat", 90); 
        set("chat_msg_combat", ({
                 (: perform_action, "sword.tun" :),
                (: perform_action, "sword.ding" :),
                 (: perform_action, "finger.tan" :),
                (: perform_action, "finger.feng" :),
                  (: perform_action, "finger.ci" :),
                (: perform_action, "finger.liujian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        })   );
        setup();
        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object(__DIR__"obj/sengrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 100 && ob->query("family/master_id")=="ku rong")
        {
                command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);
        }
}

void attempt_apprentice(object ob)
{   
        string name,new_name;
        if((!ob->query("family") || ob->query("family")["family_name"]!="������"))
        {
                command("say ����������ӣ���ˡ���Ĳ������㡣");
                
                return ;
        }      
        if ((int)ob->query_skill("kurong-changong", 1) < 200) {
                command("say �������������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڿ��������϶��µ㹦��");
                return ;
        } 
        if ((int)ob->query_skill("yiyang-zhi", 1) < 180) {
                command("say ���ŵ������������Զμ�һ��ָΪ�����ġ�"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "���һ��ָ���������");
                return ;
        }
        if ((int)ob->query_skill("tiannan-bufa", 1) < 180) {
                command("say ����Ṧ���󻹲���ô��ѽ��"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                return ;
        }
        if ((int)ob->query_skill("buddhism", 1) < 200) {
                command("say ����֮�ˣ�����Ϊ�ȣ����������˷��ŵմ�������ѧ�÷�ҵľ���ɡ�");
                command("say �������ķ����棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }
        if (ob->query_int() < 35) {
                command("say ���������书ȫ������");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return ;
        }
        if ((int)ob->query("shen") <300000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }
        if ((int)ob->query("score") <450) {
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
        ob->set("family/generation", 6);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����±��ֱ����� !");
                return ;
}
