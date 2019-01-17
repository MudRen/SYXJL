//
// /kungfu/class/xueshan/lingzhi.c  ��������
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��������", ({ "lingzhi shangren", "shangren" }));
        set("long",@LONG
����������ѩɽ���е�λ�ϸߵ����
����һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        //set("nickname","����");
        set("title",HIY "������" NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 28);
        set("dex", 26);
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 20);
        set("combat_exp", 500000);
        set("score", 80000);

        set_skill("mizong-xinfa", 60);
        set_skill("literate", 60);
        set_skill("force", 100);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 80);
        set_skill("parry", 80);
        set_skill("staff", 60);
        set_skill("xiangmo-chu", 80 );
        set_skill("hammer",50);
        set_skill("riyue-lun",50);
        set_skill("unarmed", 110);
        set_skill("yujiamu-quan", 100);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "yujiamu-quan");
        map_skill("staff", "xiangmo-chu");
        map_skill("hammer", "riyue-lun");

        create_family("ѩɽ��", 4, "������");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/c-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("gold",1);

}

void init()
{ 
        object ob;

        ::init();

        ob = this_player();
       if((int)ob->query("score")<-51&&ob->query("family/master_id")=="lingzhi shangren")
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

        if ((int)ob->query_skill("mizong-xinfa", 1) < 40) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

        command("say �ʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));

        ob->set("title","����");
}
