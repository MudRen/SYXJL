// duanzc.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("������", ({ "duan zhengchun", "duan" }));
        set("nickname", "����������");
        set("long", 
                "�����Ǻպ������Ĵ���������������������۵����ֵܶ�������\n"
                "������һ�׻����ķ�װ��\n"
                "�������Ѿ���ʮ��ͷ�������С�����Կ���������ʱһ���ܿ�����\n");
        set("title", "����������ү");
        set("gender", "����");
        set("age", 41);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        set("per", 28);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 2000000);
        set("score", 5000);
        set("shen", 50000);
        set_skill("force", 150);
        set_skill("tiannan-bufa", 150);
        set_skill("dodge", 140);
        set_skill("jinyu-quan", 150);
        set_skill("strike", 150);
        set_skill("yiyang-zhi", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("duanjia-jian", 60);
        set_skill("literate", 200);
        set_skill("cuff", 100);
        set_skill("kurong-changong", 200);
        set_skill("finger", 150);
        set_skill("wuluo-zhang", 150);
 
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("strike", "wuluo-zhang");
        map_skill("sword", "duanjia-jian");
        map_skill("finger", "yiyang-zhi");
        map_skill("parry", "wuluo-zhang");
        prepare_skill("strike", "wuluo-zhang");

        create_family("��������",1, "��ү");

        set("inquiry", ([
                "�ؼ�" : (: ask_me :),
        ]));

        set("book_count", 1);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "strike.xsj" :),
                (: perform_action, "strike.dsj" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object(__DIR__"obj/hlcloth")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("score") < 300) {
                command("say ��ʦ��...��......��");
                command("say �����ô�������������ô������������а����ʿ���㻹����ذɣ�");
                return;
        }
 
        if (((int)ob->query_skill("force",1) < 100) || ((int)ob->query_skill("kurong-changong",1) < 100))
        {
                command("say �ҿ�" + RANK_D->query_respect(ob) + "���ڹ���Ϊ�����Բ���ɡ�");
                return;
        }
        if (((int)ob->query_skill("sword",1) < 100) || ((int)ob->query_skill("duanjia-jian",1) < 100))
        {
                command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ķμҽ�����ûѧ���Ұɡ�");
                return;
        }
        if (((int)ob->query_skill("dodge",1) < 100) || ((int)ob->query_skill("tiannan-bufa",1) < 100))
        {
                command("say �ҿ�" + RANK_D->query_respect(ob) + "�����ϲ���������Ŭ����");
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
        ob = new(__DIR__"obj/finger_book");
        ob->move(this_player());
        return "�ðɣ��Ȿ��һ���ؼ������û�ȥ�ú����С�";
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
