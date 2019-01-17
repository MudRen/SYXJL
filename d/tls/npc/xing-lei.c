#include <ansi.h>
inherit NPC;
inherit F_MASTER;
//string ask_for_join();

void create()
{
        set_name("����", ({"xing lei","lei",}));
        set("long",
                "����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
                "�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
        );


        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 40);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 700);
        set("max_jing", 400);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 2000);

        set_skill("force", 130);
        set_skill("kurong-changong", 150);
        set_skill("dodge",130);
        set_skill("tiannan-bufa", 130);
        set_skill("jinyu-quan", 130);
        set_skill("unarmed", 130);
        set_skill("parry", 130);
        set_skill("buddhism", 170);
        set_skill("literate", 100);
        set_skill("finger", 130); 
        set_skill("sword", 135);
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("unarmed", "jinyu-quan");
        map_skill("parry", "jinyu-quan");

        prepare_skill("unarmed", "jinyu-quan");

        create_family("������", 8, "����");

        setup();
}

void init()
{
        object me;

        ::init();
        
        me = this_player();

        if((int)me->query("score") < 0 && me->query("family/master_id")=="xing lei")
        {
                command("chat "+me->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                command("expell "+ me->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);
        }
}

void attempt_apprentice(object ob)
{        
        string name,new_name;
        if((!ob->query("family") || ob->query("family")["family_name"]!="������"))
        {
                command("say �����Ǵ���ʼ���Ժ����ͽ�Ǻ��ϸ�ġ�");
                command("say ��ͱ��º��޹�ϵ���˻��Ӻ�˵��");
                
                return ;
        } 
        if((int)ob->query("shen") <30000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з���,���Ƿ����ò�����");
                ob->set("family/family_name","��������");
                return ;
        }
        if((int)ob->query("score") <250) {
                command("say ���ʦ�ŵ��ҳϳ̶Ȼ��д����죡");
                ob->set("family/family_name","��������");
                return;
        }
         if((string)this_player()->query("family/master_id")!="duan zhengchun" )
        {
                command("say û����������ͬ��ƶɮ�������㣿\n");
                command("say ���Ȼ�ȥ�õ���ү��ͬ�������ɡ�\n");   
                ob->set("family/family_name","��������");     
                return ;
        }
                command("chat ����,����...����ɵö���ù�");
                command("party ��ɮ����һͽ��,����Ժ�ú��д衣");
                command("recruit " + ob->query("id"));
                name = ob->query("name");     
                new_name = "��" + name[2..3];
                ob->set("class", "bonze");
                ob->set("name", new_name);
                ob->set("family/generation", 9);
                command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
                return;}

