// duanwuwei.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("����η", ({ "duan wuwei", "duan" }));
        set("title", "���������ҳ�");
        set("nickname", HIC "˭Ҳ����" NOR );
        set("long", "���Ǵ�������������ҳ���\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 700);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 40);
        set("combat_exp", 300000);
        set("score", 2000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("duanjia-jian", 100);
        set_skill("literate", 80);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("kurong-changong", 100);
        set_skill("jinyu-quan", 100);
        set_skill("tiannan-bufa", 100);
        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("cuff", "jinyu-quan");
        map_skill("sword", "duanjia-jian");
        map_skill("parry", "duanjia-jian");
        
        create_family("��������",2, "�ҳ�");

        set("inquiry", ([
                "�ؼ�" : (: ask_me :),
        ]));

        set("book_count", 1);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",20 );
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say ��ʦ��...��......��");
                command("say ������ү��������Ҫ���Ǻ��ϸ�ģ���ô������������а����ʿ���㻹����ذɣ�");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "��������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵĽ����ؼ��Ѿ��������ˡ�";
        add("book_count", -1);
        ob = new(__DIR__"obj/sword_book");
        ob->move(this_player());
        return "�ðɣ��Ȿ������Ҫ��������ȥ�úñ��ܣ���ǧ���Ū���ˣ�";
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="duan wuwei")
        {
                      command("chat "+ob->query("name")+"!�����ְ��಻���������������ҹ���ȥ��\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","��������" + RED + "��ͽ" NOR);   
        }
}
