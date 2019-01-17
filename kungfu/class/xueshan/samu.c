//
// /kungfu/class/xueshan/samu.c  ��ľ���
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��ľ���", ({ "samu huofo", "huofo" }));
        set("long",@LONG
��ľ�����ѩɽ���е��ĸ�ɮ���Է��о�����о���
����һ����ɫ���ģ�ͷ��ɮñ��һ��������˼�����ӡ�
LONG
        );
        set("title", HIY "���" NOR);
        set("gender", "����");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1200000);
        set("score", 100000);

        set_skill("mizong-xinfa", 120);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 120);
        set_skill("shenkong-xing", 100);
        set_skill("unarmed", 120);
        set_skill("yujiamu-quan", 100);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 100);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");


        create_family("ѩɽ��", 3, "���");
        set("class", "bonze");

        setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
         add_money("gold",5);
}

void init()
{ 
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<-51&&ob->query("family/master_id")=="samu huofo")
        {
                      command("chat "+ob->query("name")+"! װʲô������ʿ���Ӵ��Ժ���Ͳ�Ҫ�ٵ�ѩɽ������! \n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","ѩɽ��" + RED + "��ͽ" NOR);   
        }
//        add_action("do_kneel", "kneel");

}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("class") != "bonze") {
                command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("family/family_name") != "ѩɽ��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
        }

        if ((int)ob->query_skill("mizong-xinfa", 1) < 60) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

        command("smile");
        command("nod");
        command("say �������ѧϰ�𷨰ɣ�");
        command("recruit " + ob->query("id"));

        ob->set("title","������");
}

